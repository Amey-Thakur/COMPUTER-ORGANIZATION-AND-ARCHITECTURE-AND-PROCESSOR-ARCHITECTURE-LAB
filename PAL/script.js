/* 
 * ================================================================
 *   Computer Organization (COA) / PAL Lab - Script
 * ================================================================
 *   Author: Amey Thakur
 *   GitHub: https://github.com/Amey-Thakur
 *   Course: COA & Processor Architecture Lab
 *   Roll No: 50
 *   Batch: B3
 *   License: CC BY 4.0
 * ================================================================
 */

// =========================================
//   CONSOLE EASTER EGG 🥚
// =========================================
console.log(
    "%c💻 PAL Lab Portfolio",
    "font-size: 28px; font-weight: bold; color: #2563eb; text-shadow: 2px 2px 0 #0f172a;"
);
console.log(
    "%c👋 Hey architect! Ready to design some circuits?",
    "font-size: 14px; color: #64748b;"
);
console.log(
    "%c--------------------------------------------------",
    "color: #2563eb;"
);
console.log(
    "%cThis site is protected by Low-Level Logic Locks. 🔐",
    "font-weight: 600; color: #1e293b;"
);

// Global Variables
let currentTheme = localStorage.getItem('theme') || 'light';
const themeToggleBtn = document.getElementById('theme-toggle');
const root = document.documentElement;

// =========================================
//   SKELETON LOADER & INITIALIZATION
// =========================================
document.addEventListener('DOMContentLoaded', () => {
    // Theme Initialization
    const savedTheme = localStorage.getItem('theme') || 'light';
    setTheme(savedTheme);

    // Hide Loader after delay
    const loader = document.getElementById('skeleton-loader');
    if (loader) {
        setTimeout(() => {
            loader.classList.add('fade-out');
            setTimeout(() => loader.style.display = 'none', 500);
        }, 1500);
    }

    if (themeToggleBtn) {
        themeToggleBtn.addEventListener('click', () => {
            const currentTheme = root.getAttribute('data-theme');
            const newTheme = currentTheme === 'light' ? 'dark' : 'light';
            setTheme(newTheme);
        });
    }

    // =========================================
    //   LOW-LEVEL SECURITY & ANTI-CLICK
    // =========================================
    document.addEventListener('contextmenu', (e) => e.preventDefault());
    document.addEventListener('dragstart', (e) => e.preventDefault());
    document.addEventListener('keydown', (e) => {
        if (
            e.key === 'F12' ||
            (e.ctrlKey && e.shiftKey && (e.key === 'I' || e.key === 'J' || e.key === 'C')) ||
            (e.ctrlKey && e.key === 'u')
        ) {
            e.preventDefault();
        }
    });

    // Scroll Reveal Logic
    const revealElements = document.querySelectorAll('.reveal, .reveal-left, .reveal-right');
    const revealObserver = new IntersectionObserver((entries) => {
        entries.forEach(entry => {
            if (entry.isIntersecting) {
                entry.target.classList.add('active');
            }
        });
    }, { threshold: 0.1, rootMargin: "0px 0px -50px 0px" });
    revealElements.forEach(el => revealObserver.observe(el));

    // Stats Counter Animation
    const statsObserver = new IntersectionObserver((entries, observer) => {
        entries.forEach(entry => {
            if (entry.isIntersecting) {
                const counters = entry.target.querySelectorAll('.stat-number');
                counters.forEach(counter => {
                    const target = +counter.getAttribute('data-target');
                    const suffix = counter.getAttribute('data-suffix') || '';
                    const duration = 2000;
                    const increment = target / (duration / 16);

                    let current = 0;
                    const updateCounter = () => {
                        current += increment;
                        if (current < target) {
                            counter.textContent = Math.ceil(current) + suffix;
                            requestAnimationFrame(updateCounter);
                        } else {
                            counter.textContent = target + suffix;
                        }
                    };
                    updateCounter();
                });
                observer.unobserve(entry.target);
            }
        });
    }, { threshold: 0.5 });

    const statsSection = document.querySelector('.stats-container');
    if (statsSection) statsObserver.observe(statsSection);

    // Award Badge (3D Flip)
    const awardScene = document.querySelector('.award-scene');
    const awardCard = document.querySelector('.award-badge-card');
    const awardMsg = document.getElementById('award-msg');
    const messages = [
        "Architecture Decoded! 🏛️",
        "Memory Mapped! 🧠",
        "Logic Gated! 🚪",
        "Pipeline Flushed! 🚿",
        "Cache Hit! 🎯",
        "Mega Thanks! ❤️",
        "Mega-Bit Magic! ✨",
        "Mega Appreciation! 🌟",
        "Mega Gratitude! 🙏",
        "Mega-Force! ⚡",
        "Mega Heart! ❤️",
        "Register Renamed! 🏷️",
        "ALU Optimized! 🔢",
        "Bus Authenticated! 🚌",
        "Interrupt Handled! ⚠️",
        "Mega Thanks! ❤️",
        "Mega Thanks! ❤️",
        "Mega-Bit Magic! ✨",
        "Mega Appreciation! 🌟"
    ];

    if (awardScene && awardCard && awardMsg) {
        awardScene.addEventListener('click', () => {
            if (!awardCard.classList.contains('flipped')) {
                awardMsg.textContent = messages[Math.floor(Math.random() * messages.length)];
                awardCard.classList.add('flipped');
                playCelebrateSound();
                setTimeout(() => awardCard.classList.remove('flipped'), 3000);
            }
        });
    }

    // Initialize Productivity Tools
    initCommandPalette();
    initBoothsVisualizer();

    const kbdHint = document.getElementById('kbd-hint');
    if (kbdHint) setTimeout(() => kbdHint.classList.add('hidden'), 8000);
});

// =========================================
//   THEME MANAGEMENT
// =========================================
function setTheme(theme) {
    root.setAttribute('data-theme', theme);
    localStorage.setItem('theme', theme);

    if (themeToggleBtn) {
        const icon = themeToggleBtn.querySelector('i');
        if (icon) {
            if (theme === 'dark') {
                icon.classList.remove('fa-moon');
                icon.classList.add('fa-sun');
            } else {
                icon.classList.remove('fa-sun');
                icon.classList.add('fa-moon');
            }
        }
    }
}

// =========================================
//   SOUND EFFECT (Appreciation Chime)
// =========================================
function playCelebrateSound() {
    try {
        const AudioContext = window.AudioContext || window.webkitAudioContext;
        if (!AudioContext) return;
        const audioCtx = new AudioContext();

        function playNote(freq, start, duration) {
            const osc = audioCtx.createOscillator();
            const gain = audioCtx.createGain();
            osc.type = 'sine';
            osc.frequency.setValueAtTime(freq, start);
            gain.gain.setValueAtTime(0.1, start);
            gain.gain.exponentialRampToValueAtTime(0.01, start + duration);
            osc.connect(gain);
            gain.connect(audioCtx.destination);
            osc.start(start);
            osc.stop(start + duration);
        }

        playNote(523.25, audioCtx.currentTime, 0.2); // C5
        playNote(783.99, audioCtx.currentTime + 0.1, 0.4); // G5
    } catch (e) { console.error('Audio failed', e); }
}

// =========================================
//   COMMAND PALETTE LOGIC
// =========================================
function initCommandPalette() {
    const overlay = document.getElementById('cmd-overlay');
    const input = document.getElementById('cmd-input');
    const resultsContainer = document.getElementById('cmd-results');
    const kbdHint = document.getElementById('kbd-hint');

    if (!overlay || !input || !resultsContainer) return;

    let selectedIndex = 0;
    let results = [];
    const commands = [
        { type: 'Command', name: 'Toggle Theme', icon: 'fa-adjust', action: () => document.getElementById('theme-toggle').click() },
        { type: 'Command', name: 'Scroll to Top', icon: 'fa-arrow-up', action: () => window.scrollTo({ top: 0, behavior: 'smooth' }) },
        { type: 'Command', name: 'Go to Experiments', icon: 'fa-flask', action: () => document.getElementById('experiments').scrollIntoView({ behavior: 'smooth' }) },
        { type: 'Command', name: 'Go to The Wall', icon: 'fa-users', action: () => document.getElementById('the-wall').scrollIntoView({ behavior: 'smooth' }) },
        { type: 'Command', name: 'Visualize Booth\'s', icon: 'fa-calculator', action: () => document.getElementById('logic-visualizer').scrollIntoView({ behavior: 'smooth' }) },
    ];

    // Scrape Experiments
    const experiments = Array.from(document.querySelectorAll('.card-custom h5')).map(h5 => ({
        type: 'Experiment',
        name: h5.textContent.trim(),
        icon: 'fa-flask',
        action: () => {
            h5.scrollIntoView({ behavior: 'smooth', block: 'center' });
            const card = h5.closest('.card-custom');
            if (card) {
                card.style.transition = 'all 0.3s ease';
                card.style.transform = 'scale(1.02)';
                card.style.boxShadow = '0 0 0 4px var(--accent-color)';
                setTimeout(() => {
                    card.style.transform = 'scale(1)';
                    card.style.boxShadow = 'none';
                }, 1500);
            }
        }
    }));

    const searchIndex = [...commands, ...experiments];

    function openPalette() {
        overlay.classList.add('active');
        input.value = '';
        input.focus();
        filterResults('');
        if (kbdHint) kbdHint.classList.add('hidden');
    }

    function closePalette() {
        overlay.classList.remove('active');
    }

    function filterResults(query) {
        const q = query.toLowerCase();
        results = searchIndex.filter(item =>
            item.name.toLowerCase().includes(q)
        ).slice(0, 10);

        if (q === '') results = commands;
        renderResults();
    }

    function renderResults() {
        resultsContainer.innerHTML = '';
        if (results.length === 0) {
            resultsContainer.innerHTML = '<div class="text-center p-3 text-secondary">No matching commands or notes found.</div>';
            return;
        }

        results.forEach((item, index) => {
            const div = document.createElement('div');
            div.className = `cmd-item ${index === selectedIndex ? 'selected' : ''}`;
            div.innerHTML = `
                <div class="d-flex align-items-center">
                    <div class="cmd-item-icon"><i class="fas ${item.icon}"></i></div>
                    <span class="cmd-item-text">${item.name}</span>
                </div>
                <span class="cmd-item-type">${item.type}</span>
            `;
            div.addEventListener('click', () => {
                item.action();
                closePalette();
            });
            div.addEventListener('mouseenter', () => {
                selectedIndex = index;
                renderResults();
            });
            resultsContainer.appendChild(div);
        });

        const selectedEl = resultsContainer.children[selectedIndex];
        if (selectedEl) selectedEl.scrollIntoView({ block: 'nearest' });
    }

    // Unified Keyboard Listener
    document.addEventListener('keydown', (e) => {
        if (e.key === 'F12' || (e.ctrlKey && e.shiftKey && (e.key === 'I' || e.key === 'J' || e.key === 'C')) || (e.ctrlKey && e.key === 'u')) {
            e.preventDefault();
            return;
        }

        if ((e.ctrlKey || e.metaKey) && e.key.toLowerCase() === 'k') {
            e.preventDefault();
            if (overlay.classList.contains('active')) closePalette();
            else openPalette();
            return;
        }

        if (overlay.classList.contains('active')) {
            if (e.key === 'Escape') { closePalette(); return; }
            if (e.key === 'ArrowDown') { e.preventDefault(); selectedIndex = (selectedIndex + 1) % results.length; renderResults(); return; }
            if (e.key === 'ArrowUp') { e.preventDefault(); selectedIndex = (selectedIndex - 1 + results.length) % results.length; renderResults(); return; }
            if (e.key === 'Enter') { e.preventDefault(); if (results[selectedIndex]) { results[selectedIndex].action(); closePalette(); } return; }
            return;
        }

        if (e.ctrlKey || e.metaKey || e.altKey) return;
        const activeTag = document.activeElement ? document.activeElement.tagName : '';
        if (activeTag === 'INPUT' || activeTag === 'TEXTAREA') return;

        if (e.key.toLowerCase() === 't') { e.preventDefault(); document.getElementById('theme-toggle').click(); }
        if (e.key.toLowerCase() === 'h') { e.preventDefault(); window.scrollTo({ top: 0, behavior: 'smooth' }); }
        if (e.key.toLowerCase() === 'e') { e.preventDefault(); document.getElementById('experiments').scrollIntoView({ behavior: 'smooth' }); }
        if (e.key.toLowerCase() === 'w') { e.preventDefault(); document.getElementById('the-wall').scrollIntoView({ behavior: 'smooth' }); }
        if (e.key.toLowerCase() === 'v') { e.preventDefault(); document.getElementById('logic-visualizer').scrollIntoView({ behavior: 'smooth' }); }
    });

    input.addEventListener('input', (e) => {
        selectedIndex = 0;
        filterResults(e.target.value);
    });
}

// =========================================
//   BOOTH'S ALGORITHM VISUALIZER
// =========================================
function initBoothsVisualizer() {
    const M_input = document.getElementById('multiplicand');
    const Q_input = document.getElementById('multiplier');
    const visualizeBtn = document.getElementById('visualize-btn');
    const outputDiv = document.getElementById('booths-output');

    if (!M_input || !Q_input || !visualizeBtn || !outputDiv) return;

    function toBin(n, bits) {
        let binary = (n >>> 0).toString(2);
        if (binary.length > bits) return binary.slice(-bits);
        return binary.padStart(bits, n < 0 ? '1' : '0'); // Signed extension
    }

    function addBinary(a, b) {
        // Simple addition for visualization purposes
        // In real algo we do bitwise addition
        let sum = parseInt(a, 2) + parseInt(b, 2);
        return toBin(sum, a.length);
    }

    function log(text, type = '') {
        const line = document.createElement('div');
        line.className = `terminal-line ${type}`;
        line.innerHTML = text; // Allow HTML for colors
        outputDiv.appendChild(line);
        outputDiv.scrollTop = outputDiv.scrollHeight;
    }

    visualizeBtn.addEventListener('click', async () => {
        const mVal = parseInt(M_input.value);
        const qVal = parseInt(Q_input.value);

        // Set loading state
        const btnIcon = visualizeBtn.querySelector('i');
        const originalIconClass = btnIcon.className;
        btnIcon.className = 'fas fa-spinner fa-spin me-2';
        visualizeBtn.disabled = true;

        if (isNaN(mVal) || isNaN(qVal)) {
            log('<span class="prompt">Error:</span> Please enter valid integer inputs.', 'error');
            btnIcon.className = originalIconClass;
            visualizeBtn.disabled = false;
            return;
        }

        if (mVal < -8 || mVal > 7 || qVal < -8 || qVal > 7) {
            log('<span class="prompt">Warning:</span> Inputs -8 to 7 suggested for 4-bit visualization.', 'output');
        }

        // Clear previous output except header
        outputDiv.innerHTML = `
            <div class="terminal-line"><span class="prompt">amey@pal:~$</span> ./booths_visualizer ${mVal} ${qVal}</div>
            <div class="terminal-line output success">Initializing Booth's Algorithm (4-bit)...</div>
        `;

        // Booth's Algo Simulation (4-bit for education)
        let A = 0;
        let Q = qVal;
        let M = mVal;
        let Q_minus_1 = 0;
        let count = 4; // 4-bit cycle

        log(`<span class="command-text">Init:</span> A=0000 Q=${toBin(Q, 4)} Q-1=0 M=${toBin(M, 4)}`);

        // Helper delay
        const delay = (ms) => new Promise(res => setTimeout(res, ms));

        for (let i = 0; i < count; i++) {
            await delay(800);
            log(`--- Cycle ${i + 1} ---`, 'output');

            // Check Q[0] and Q[-1]
            // We need to access bits. For simple integer simulation:
            let q0 = Q & 1;

            if (q0 === 1 && Q_minus_1 === 0) {
                log(`<span class="prompt">1 0 -> Sub:</span> A = A - M`);
                A = A - M;
            } else if (q0 === 0 && Q_minus_1 === 1) {
                log(`<span class="prompt">0 1 -> Add:</span> A = A + M`);
                A = A + M;
            } else {
                log(`<span class="output">0 0 / 1 1 -> No Op</span>`);
            }

            // ASR
            log(`&nbsp;&nbsp;State: A=${toBin(A, 4)} Q=${toBin(Q, 4)} Q-1=${Q_minus_1}`, 'text-secondary');

            await delay(400);

            // Perform Arithmetic Shift Right on {A, Q, Q-1}
            // Concatenate A and Q into a single value, shift, then split
            // This is tricky with pure JS integers due to overflow/signedness.
            // Let's do it logically:

            let combined = (A << 5) | (Q << 1) | Q_minus_1;
            // Actually, simplified ASR logic:

            let next_Q_minus_1 = Q & 1;
            let next_Q = (Q >>> 1) | ((A & 1) << 3); // Shift Q right, bring in A's LSB
            let next_A = (A >> 1); // Arithmetic shift A

            // Wait, standard ASR on [A Q Q-1]
            // Q_-1 becomes Q_0
            // Q shifts right, MSB becomes A_0
            // A shifts right, MSB remains same (sign extension)

            let a_lsb = A & 1;
            Q_minus_1 = Q & 1; // Update Q-1 first? No, ASR happens together.
            // Actually, step 2 is "Arithmetic Shift Right (A, Q, Q-1)"

            // Q right shift
            let q_sign_bit = (Q & 0x8) ? 1 : 0; // Not needed, comes from A
            let next_Q_val = (Q >>> 1) | (a_lsb << 3);

            // A right shift (arithmetic) preserves sign
            let next_A_val = A >> 1; // JS >> is arithmetic shift

            // BUT wait, Q_minus_1 just TAKES the old Q_0
            let old_Q_0 = Q & 1;

            A = next_A_val;
            Q = next_Q_val;
            Q_minus_1 = old_Q_0;

            log(`<span class="prompt">ASR -></span> A=${toBin(A, 4)} Q=${toBin(Q, 4)} Q-1=${Q_minus_1}`);
        }

        await delay(800);

        // Final Result
        // Combine A and Q
        // In JS, just calculating M * Q is easier to show verification
        let result = mVal * qVal;

        log(`<div class="terminal-line output success" style="margin-top: 10px;">Calculation Complete!</div>`);
        log(`Result (Decimal): ${result}`);
        log(`<span class="prompt">amey@pal:~$</span> <span class="cursor">_</span>`);

        // Restore button state
        btnIcon.className = originalIconClass;
        visualizeBtn.disabled = false;
    });
}

/* 
 * =========================================
 *   SECURITY: ANTI-SELECT & ANTI-INSPECT
 * =========================================
 */

// Disable Right Click
document.addEventListener('contextmenu', (e) => e.preventDefault());

// Disable Key Shortcuts for Inspecting
document.addEventListener('keydown', (e) => {
    // F12, Ctrl+Shift+I, Ctrl+Shift+J, Ctrl+U
    if (
        e.keyCode === 123 ||
        (e.ctrlKey && e.shiftKey && (e.keyCode === 73 || e.keyCode === 74)) ||
        (e.ctrlKey && e.keyCode === 85)
    ) {
        e.preventDefault();
        return false;
    }
});
