__int64 __fastcall rmnet_qmap_send(__int64 a1, unsigned __int8 a2, char a3)
{
  __int64 v4; // x2
  __int64 v6; // x3
  __int64 v7; // x4
  _DWORD *v8; // x9
  __int64 result; // x0
  __int64 v12; // x0
  __int64 (__fastcall *v13)(__int64, __int64, __int64); // x8
  __int64 v14; // x1

  v4 = *(unsigned int *)(a1 + 112);
  if ( a2 == 0xFF || !real_data_dev )
  {
    v12 = rmnet_ctl_handle;
    v13 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(rmnet_ctl + 16);
    if ( *((_DWORD *)v13 - 1) != 1347576298 )
      __break(0x8228u);
    result = v13(v12, a1, v4);
    if ( (_DWORD)result )
    {
      printk(&unk_2D3AA, v14);
      return 4294967226LL;
    }
  }
  else
  {
    *(_QWORD *)(a1 + 16) = real_data_dev;
    *(_WORD *)(a1 + 180) = -1792;
    v6 = *(_QWORD *)(a1 + 224);
    v7 = *(unsigned int *)(a1 + 112);
    v8 = *(_DWORD **)(rmnet_ctl + 24);
    if ( *(v8 - 1) != -1286836228 )
      __break(0x8229u);
    ((void (__fastcall *)(__int64, const char *, _QWORD, __int64, __int64))v8)(3, "TXI", 0, v6, v7);
    rmnet_map_tx_qmap_cmd(a1, a2, a3 & 1);
    return 0;
  }
  return result;
}
