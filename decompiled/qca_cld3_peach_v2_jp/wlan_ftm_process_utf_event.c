__int64 __fastcall wlan_ftm_process_utf_event(__int64 a1, __int64 a2, unsigned int a3)
{
  __int64 comp_private_obj; // x0
  int v7; // w23
  unsigned __int64 v8; // x8
  __int64 result; // x0
  unsigned int v10; // w21
  __int64 v11; // x22
  char v12; // w10
  __int64 v13; // x2
  int v14; // w9

  comp_private_obj = wlan_objmgr_pdev_get_comp_private_obj(a1, 0x17u);
  if ( !comp_private_obj )
    return 16;
  v7 = *(_DWORD *)(a2 + 8);
  *(_BYTE *)(comp_private_obj + 16) = v7 & 0xF;
  if ( (v7 & 0xF) != 0 )
  {
    if ( a3 > 0x800 )
      return 16;
  }
  else
  {
    *(_BYTE *)(comp_private_obj + 17) = 0;
    *(_QWORD *)(comp_private_obj + 32) = 0;
    if ( a3 > 0x800 )
      return 16;
  }
  v8 = *(_QWORD *)(comp_private_obj + 32);
  if ( v8 <= 2064 - a3 )
  {
    v10 = a3 - 16;
    v11 = comp_private_obj;
    qdf_mem_copy((void *)(*(_QWORD *)(comp_private_obj + 8) + v8), (const void *)(a2 + 16), v10);
    v12 = *(_BYTE *)(v11 + 17);
    v13 = *(_QWORD *)(v11 + 32) + v10;
    *(_BYTE *)(v11 + 17) = v12 + 1;
    *(_QWORD *)(v11 + 32) = v13;
    if ( (unsigned __int8)v7 >> 4 != (unsigned __int8)(v12 + 1) )
      return 0;
    v14 = *(_DWORD *)(v11 + 40);
    *(_QWORD *)(v11 + 24) = v13;
    if ( v14 != 2 )
      return 0;
    result = wlan_cfg80211_ftm_rx_event(a1, *(_QWORD *)(v11 + 8));
    if ( !(_DWORD)result )
    {
      *(_DWORD *)(v11 + 40) = 3;
      return result;
    }
  }
  return 16;
}
