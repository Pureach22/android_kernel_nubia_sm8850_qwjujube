__int64 __fastcall lim_prepare_and_send_disassoc(__int64 a1, __int64 a2)
{
  char v4; // w8
  int v5; // w8
  int v6; // w9
  __int64 v7; // x0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  unsigned int v16; // w1
  __int64 result; // x0
  __int64 v18; // [xsp+0h] [xbp-50h] BYREF
  int *v19; // [xsp+8h] [xbp-48h]
  __int64 v20; // [xsp+10h] [xbp-40h]
  __int64 v21; // [xsp+18h] [xbp-38h]
  __int64 v22; // [xsp+20h] [xbp-30h]
  __int64 v23; // [xsp+28h] [xbp-28h]
  int v24; // [xsp+30h] [xbp-20h] BYREF
  __int128 v25; // [xsp+34h] [xbp-1Ch] BYREF
  __int16 v26; // [xsp+44h] [xbp-Ch]
  __int64 v27; // [xsp+48h] [xbp-8h]

  v27 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  *(_QWORD *)&v25 = 0;
  v24 = 1446920;
  v4 = *(_BYTE *)(a2 + 4);
  v22 = 0;
  v23 = 0;
  LOBYTE(v25) = v4;
  v20 = 0;
  v21 = 0;
  v18 = 0;
  v19 = nullptr;
  v26 = 0;
  *((_QWORD *)&v25 + 1) = 0;
  qdf_mem_copy((char *)&v25 + 1, (const void *)(a1 + 24), 6u);
  v5 = *(_DWORD *)(a2 + 8);
  v6 = *(_DWORD *)(a2 + 12);
  *(_DWORD *)((char *)&v25 + 7) = *(_DWORD *)((char *)&v25 + 1);
  *(_WORD *)((char *)&v25 + 11) = *(_WORD *)((char *)&v25 + 5);
  HIWORD(v25) = v6;
  if ( v5 == 9 )
  {
    HIWORD(v25) = -1;
  }
  else if ( v6 == 65520 )
  {
    v26 = 257;
  }
  else if ( v5 == 18 )
  {
    LOBYTE(v26) = 1;
  }
  v7 = *(_QWORD *)(a1 + 16);
  v19 = &v24;
  LOWORD(v18) = 5128;
  if ( (unsigned int)wlan_vdev_is_restart_progress(v7) )
    v16 = 12;
  else
    v16 = 6;
  result = wlan_vdev_mlme_sm_deliver_evt(
             *(_QWORD *)(a1 + 16),
             v16,
             0x30u,
             (__int64)&v18,
             v8,
             v9,
             v10,
             v11,
             v12,
             v13,
             v14,
             v15);
  _ReadStatusReg(SP_EL0);
  return result;
}
