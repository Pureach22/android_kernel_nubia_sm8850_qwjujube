__int64 __fastcall fan_level_show(int a1, int a2, char *s)
{
  return sprintf(
           s,
           "%d\n",
           *(unsigned __int8 *)(*(_QWORD *)(chip + 8) + (*(unsigned __int8 *)(*(_QWORD *)(chip + 8) + 12LL) ^ 1LL)));
}
