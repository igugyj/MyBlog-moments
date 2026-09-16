const NICKS = {
  penguin: "Пингвинёнок",
  park: "small park 👑",
  bear: "安妮的跟屁熊 👑",
  wind: "China 清風、微凉",
  aion: "AION UNTO TELOS 👑",
  pingvin4ik: "Pingvin4ik",
  zhuoshui: "浊水",
};

document.querySelectorAll("[data-nick]").forEach((el) => {
  const key = el.dataset.nick;
  if (key in NICKS) el.textContent = NICKS[key];
});
