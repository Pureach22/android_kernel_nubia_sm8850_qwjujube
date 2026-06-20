__int64 __fastcall adreno_gpufault_stats(__int64 a1, __int64 a2, __int64 a3, char a4)
{
  _DWORD *v5; // x24
  __int64 result; // x0

  v5 = (_DWORD *)(a1 + 20480);
  raw_write_lock(a1 + 24284);
  if ( (a4 & 1) != 0 )
  {
    ++v5[893];
    if ( (a4 & 2) == 0 )
    {
LABEL_3:
      if ( (a4 & 4) == 0 )
        goto LABEL_4;
      goto LABEL_18;
    }
  }
  else if ( (a4 & 2) == 0 )
  {
    goto LABEL_3;
  }
  ++v5[894];
  if ( (a4 & 4) == 0 )
  {
LABEL_4:
    if ( (a4 & 8) == 0 )
      goto LABEL_5;
    goto LABEL_19;
  }
LABEL_18:
  ++v5[895];
  if ( (a4 & 8) == 0 )
  {
LABEL_5:
    if ( (a4 & 0x10) == 0 )
      goto LABEL_6;
    goto LABEL_20;
  }
LABEL_19:
  ++v5[896];
  if ( (a4 & 0x10) == 0 )
  {
LABEL_6:
    if ( (a4 & 0x20) == 0 )
      goto LABEL_7;
    goto LABEL_21;
  }
LABEL_20:
  ++v5[897];
  if ( (a4 & 0x20) == 0 )
  {
LABEL_7:
    if ( (a4 & 0x40) == 0 )
      goto LABEL_8;
    goto LABEL_22;
  }
LABEL_21:
  ++v5[898];
  if ( (a4 & 0x40) == 0 )
  {
LABEL_8:
    if ( (a4 & 0x80) == 0 )
      goto LABEL_10;
    goto LABEL_9;
  }
LABEL_22:
  ++v5[899];
  if ( a4 < 0 )
LABEL_9:
    ++v5[900];
LABEL_10:
  result = raw_write_unlock(a1 + 24284);
  if ( a2 )
  {
    a2 = *(_QWORD *)(*(_QWORD *)(a2 + 8) + 24LL);
    result = ((__int64 (__fastcall *)(__int64, __int64))add_proc_fault_list)(a1, a2);
  }
  if ( a3 )
  {
    if ( *(_QWORD *)(*(_QWORD *)(a3 + 8) + 24LL) != a2 )
      return ((__int64 (__fastcall *)(__int64))add_proc_fault_list)(a1);
  }
  return result;
}
