__int64 __fastcall aw9620x_sensy_config_get(__int64 a1, int a2, char *s)
{
  return snprintf(s, 0x1000u, "%d\n", *(unsigned __int8 *)(*(_QWORD *)(a1 + 152) + 616LL));
}
