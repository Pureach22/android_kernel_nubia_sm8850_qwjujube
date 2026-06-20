__int64 __fastcall ieee80211_nan_change_conf(__int64 a1, __int64 a2, _BYTE *a3, char a4)
{
  __int64 result; // x0
  __int64 v5; // x19
  __int64 v6; // x20
  __int64 v7; // x1
  __int64 (__fastcall *v8)(__int64, __int64, __int16 *); // x9
  __int64 v9; // x9
  __int64 v10; // x20
  __int64 v11; // x8
  __int16 v12; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v13; // [xsp+8h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_DWORD *)(a2 + 4704) != 12 )
    goto LABEL_16;
  if ( (*(_QWORD *)(a2 + 1616) & 1) == 0 )
  {
    result = 4294967196LL;
    goto LABEL_17;
  }
  v12 = *(_WORD *)(a2 + 2248);
  if ( (a4 & 1) != 0 )
    LOBYTE(v12) = *a3;
  if ( (a4 & 2) != 0 )
    HIBYTE(v12) = a3[1];
  v5 = *(_QWORD *)(a2 + 1600);
  if ( (*(_BYTE *)(v5 + 1471) & 1) == 0
    && (*(_DWORD *)(a2 + 1608) & 0x20) == 0
    && (drv_nan_change_conf___already_done & 1) == 0 )
  {
    v9 = *(_QWORD *)(a2 + 1592);
    drv_nan_change_conf___already_done = 1;
    v10 = a2;
    if ( v9 )
      v11 = v9 + 296;
    else
      v11 = a2 + 1624;
    _warn_printk("%s: Failed check-sdata-in-driver check, flags: 0x%x\n", v11);
    a2 = v10;
    __break(0x800u);
  }
  if ( !*(_QWORD *)(*(_QWORD *)(v5 + 464) + 784LL) )
  {
LABEL_16:
    result = 4294967201LL;
    goto LABEL_17;
  }
  v6 = a2;
  v7 = a2 + 4704;
  v8 = *(__int64 (__fastcall **)(__int64, __int64, __int16 *))(*(_QWORD *)(v5 + 464) + 784LL);
  if ( *((_DWORD *)v8 - 1) != 1588539577 )
    __break(0x8229u);
  result = v8(v5, v7, &v12);
  if ( !(_DWORD)result )
    *(_WORD *)(v6 + 2248) = v12;
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}
