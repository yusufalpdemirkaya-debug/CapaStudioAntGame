const express = require('express');
const path = require('path');
const fs = require('fs');

const app = express();
const PORT = process.env.PORT || 3000;

app.use(express.json());
app.use(express.static(__dirname));


app.get('/', (req, res) => {
    res.sendFile(path.join(__dirname, 'main.html'));
});


const LEADERBOARD_FILE = path.join(__dirname, 'leaderboard.json');
let leaderboardData = [];

// Load existing data on startup or initialize the file
if (fs.existsSync(LEADERBOARD_FILE)) {
    try {
        const rawData = fs.readFileSync(LEADERBOARD_FILE, 'utf8');
        leaderboardData = JSON.parse(rawData);
    } catch (err) {
        console.error('Error loading leaderboard file:', err);
    }
} else {
    fs.writeFileSync(LEADERBOARD_FILE, JSON.stringify([], null, 2));
}

app.post('/stats', (req, res) => {
    const { username, time, timestamp, signature } = req.body;

    // Basic validation for username and time
    if (!username || !time) {
        return res.status(400).json({ error: 'Incomplete data.' });
    }

    // Data is valid. Save it.
    leaderboardData.push({ username, time });
    // Persist data to the JSON file
    fs.writeFile(LEADERBOARD_FILE, JSON.stringify(leaderboardData, null, 2), (err) => {
        if (err) console.error('Error saving to leaderboard file:', err);
    });

    console.log(`Score recorded: ${username} finished in ${time}`);

    res.status(201).json({ message: 'Success! Score recorded.' });
});

app.listen(PORT, () => console.log(`Atom Heart Ant Backend running on http://localhost:${PORT}`));