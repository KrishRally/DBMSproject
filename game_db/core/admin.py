from django.contrib import admin
from .models import *
# Register your models here.
admin.site.register(Player)
admin.site.register(Team)
admin.site.register(Inventory)
admin.site.register(Item)
admin.site.register(InventoryItem)
admin.site.register(Achievement)
admin.site.register(PlayerAchievement)
admin.site.register(Stat)
admin.site.register(Friend)