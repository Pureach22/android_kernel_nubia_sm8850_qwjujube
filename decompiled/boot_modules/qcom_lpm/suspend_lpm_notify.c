__int64 __fastcall suspend_lpm_notify(__int64 a1, __int64 a2)
{
  char v2; // w8
  char v3; // w8
  unsigned __int64 v4; // x8
  unsigned __int64 v5; // x19

  if ( a2 == 3 )
  {
    v2 = 1;
    goto LABEL_5;
  }
  if ( a2 == 4 )
  {
    v2 = 0;
LABEL_5:
    suspend_in_progress = v2;
  }
  v3 = 0;
  do
  {
    v4 = (unsigned int)(-1LL << v3) & _cpu_online_mask;
    if ( !(_DWORD)v4 )
      break;
    v5 = __clz(__rbit64(v4));
    wake_up_if_idle((unsigned int)v5);
    v3 = v5 + 1;
  }
  while ( v5 < 0x1F );
  return 0;
}
