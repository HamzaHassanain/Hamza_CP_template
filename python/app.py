import pandas as pd

df = pd.read_csv("pokemon_data.csv")


df["Total"] = df["HP"] + df["Attack"]


print(df.head(5))
