void __fastcall android_rvh_is_cpu_allowed(__int64 a1, __int64 a2, unsigned int a3, _BYTE *a4)
{
  unsigned __int64 v4; // x8

  if ( (walt_disabled & 1) == 0
    && ((*(unsigned __int64 *)((char *)&_cpu_halt_mask + (((unsigned __int64)a3 >> 3) & 0x1FFFFFF8)) >> a3) & 1) != 0 )
  {
    *a4 = 0;
    if ( (*(_QWORD *)a2 & 0x400000) != 0 && (*(_WORD *)(a2 + 1728) & 4) != 0 )
      goto LABEL_10;
    v4 = (unsigned int)(_cpu_active_mask & **(_DWORD **)(a2 + 1376)) & (unsigned __int64)~_cpu_halt_mask;
    if ( (*(_BYTE *)(a2 + 70) & 0x20) != 0 )
    {
      if ( (v4 & ~_cpu_dying_mask) == 0 )
LABEL_10:
        *a4 = 1;
    }
    else if ( !v4 )
    {
      goto LABEL_10;
    }
  }
}
