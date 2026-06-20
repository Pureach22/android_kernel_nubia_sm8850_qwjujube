__int64 __fastcall drv_remove_interface(__int64 result, __int64 a2)
{
  __int64 v2; // x19
  int v3; // w8
  __int64 v4; // x1
  __int64 (__fastcall *v5)(__int64, __int64); // x9
  __int64 v6; // x9
  __int64 v7; // x20
  __int64 v8; // x8

  v2 = result;
  if ( (*(_BYTE *)(*(_QWORD *)(a2 + 1616) + 1471LL) & 1) != 0
    || (*(_DWORD *)(a2 + 1624) & 0x20) != 0
    || (drv_remove_interface___already_done & 1) != 0 )
  {
    v3 = *(_DWORD *)(a2 + 1624);
    if ( (v3 & 0x20) == 0 )
      return result;
    goto LABEL_5;
  }
  v6 = *(_QWORD *)(a2 + 1608);
  drv_remove_interface___already_done = 1;
  v7 = a2;
  if ( v6 )
    v8 = v6 + 296;
  else
    v8 = a2 + 1640;
  result = _warn_printk("%s: Failed check-sdata-in-driver check, flags: 0x%x\n", v8);
  a2 = v7;
  __break(0x800u);
  v3 = *(_DWORD *)(v7 + 1624);
  if ( (v3 & 0x20) != 0 )
  {
LABEL_5:
    *(_DWORD *)(a2 + 1624) = v3 & 0xFFFFFFDF;
    v4 = a2 + 4720;
    v5 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)(v2 + 464) + 64LL);
    if ( *((_DWORD *)v5 - 1) != 1098857213 )
      __break(0x8229u);
    return v5(v2, v4);
  }
  return result;
}
