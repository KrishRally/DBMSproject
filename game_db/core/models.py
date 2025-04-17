from django.db import models

# Create your models here.
class Team(models.Model):
    team_id = models.AutoField(primary_key=True)
    number_of_players = models.IntegerField()

class Player(models.Model):
    pid = models.AutoField(primary_key=True)
    name = models.CharField(max_length=100)
    email = models.EmailField()
    date_joined = models.DateField()
    team = models.ForeignKey(Team, on_delete=models.CASCADE)

class Inventory(models.Model):
    inv_id = models.AutoField(primary_key=True)
    player = models.OneToOneField(Player, on_delete=models.CASCADE)

class Item(models.Model):
    item_id = models.AutoField(primary_key=True)
    item_name = models.CharField(max_length=100)
    rarity = models.CharField(max_length=50)

class InventoryItem(models.Model):
    inventory = models.ForeignKey(Inventory, on_delete=models.CASCADE)
    item = models.ForeignKey(Item, on_delete=models.CASCADE)
    quantity = models.PositiveIntegerField()

class Achievement(models.Model):
    ach_id = models.AutoField(primary_key=True)
    name = models.CharField(max_length=100)
    xp = models.IntegerField()

class PlayerAchievement(models.Model):
    player = models.ForeignKey(Player, on_delete=models.CASCADE)
    achievement = models.ForeignKey(Achievement, on_delete=models.CASCADE)

class Stat(models.Model):
    stat_id = models.AutoField(primary_key=True)
    player = models.OneToOneField(Player, on_delete=models.CASCADE)
    kdratio = models.FloatField()
    match_wins = models.IntegerField()
    season = models.CharField(max_length=20)

class Friend(models.Model):
    player1 = models.ForeignKey(Player, on_delete=models.CASCADE, related_name='friend_one')
    player2 = models.ForeignKey(Player, on_delete=models.CASCADE, related_name='friend_two')        
