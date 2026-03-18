// setup typing content
const content = {
  easy: [
    {
      id: "easy-1",
      text: "The sun rose over the quiet town. Birds sang in the trees as people woke up and started their day. It was going to be a warm and sunny morning."
    },
    {
      id: "easy-2",
      text: "She walked to the store to buy some bread and milk. The shop was busy but she found what she needed quickly. On her way home, she saw a friend and waved."
    }
  ],
  medium: [
    {
      id: "medium-1",
      text: "Learning a new skill takes patience and consistent practice. Whether you're studying a language, picking up an instrument, or mastering a sport, the key is to show up every day."
    }
  ],
  hard: [
    {
      id: "hard-1",
      text: "The philosopher's argument hinged on a seemingly paradoxical assertion: that absolute freedom, pursued without constraint, inevitably undermines itself."
    }
  ]
};

// setup elements
const statWpm = document.getElementById("stat_wpm");
const statAccuracy = document.getElementById("stat_accuracy");
const statTime = document.getElementById("stat_time");
const textsElement = document.getElementById("texts");
const starterElement = document.getElementById("starterElement");
const starterBtnElement = document.getElementById("starterBtn");
const hiddenInputElement = document.getElementById("hidden-input");

// setup state
let difficulty = "easy";
let currentContent = "";
let currentIndex = 0;
let correctCount = 0;
let incorrectCount = 0;
let accuracy = 0;
let startTime = null;
let completed = false;

// setup content
function setupContent() {
  let difficultyContents = content[difficulty];
  let randomIndex = Math.floor(Math.random() * difficultyContents.length);
  currentContent = difficultyContents[randomIndex];

  textsElement.innerText = currentContent.text;
  textsElement.classList.add("blurred");
}

// render text with colors
function renderText() {
  let spanHtml = "";

  for (let i = 0; i < currentContent.text.length; i++) {
    let className = "";

    if (i < currentIndex) {
      if (currentContent.text[i] === hiddenInputElement.value[i]) {
        className = "correct";
      } else {
        className = "incorrect";
      }
    } else if (i === currentIndex) {
      className = "current";
    }

    spanHtml += `<span class="${className}">${currentContent.text[i]}</span>`;
  }

  textsElement.innerHTML = spanHtml;
}

// update WPM, accuracy, time
function updateStates() {
  const elapsedSeconds = Math.floor((Date.now() - startTime) / 1000);
  statTime.textContent = elapsedSeconds + "s";

  let wpm = 0;
  const elapsedMinutes = elapsedSeconds / 60;

  if (elapsedMinutes > 0) {
    wpm = Math.round(correctCount / 5 / elapsedMinutes);
  }
  statWpm.textContent = wpm;

  let totalTyped = correctCount + incorrectCount;
  if (totalTyped > 0) {
    accuracy = Math.round((correctCount / totalTyped) * 100);
  } else {
    accuracy = 0;
  }
  statAccuracy.textContent = accuracy + "%";

  // stop when completed
  if (currentIndex === currentContent.text.length) {
    completed = true;
  }
}

// initialization
function init() {
  setupContent();

  starterBtnElement.addEventListener("click", function () {
    startTime = Date.now(); // ✅ FIXED

    textsElement.classList.remove("blurred");
    starterElement.classList.add("hidden");

    renderText();
    hiddenInputElement.focus();

    // live timer update
    setInterval(() => {
      if (!completed && startTime) {
        updateStates();
      }
    }, 1000);

    hiddenInputElement.addEventListener("input", function (event) {
      const typedText = event.target.value;

      currentIndex = typedText.length;

      correctCount = 0;
      incorrectCount = 0;

      for (let i = 0; i < typedText.length; i++) {
        if (currentContent.text[i] === typedText[i]) {
          correctCount++;
        } else {
          incorrectCount++;
        }
      }

      renderText();
      updateStates();
    });
  });
}

init();