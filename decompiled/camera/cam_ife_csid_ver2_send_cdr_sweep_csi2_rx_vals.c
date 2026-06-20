__int64 __fastcall cam_ife_csid_ver2_send_cdr_sweep_csi2_rx_vals(__int64 result, __int64 a2, int a3)
{
  __int64 v3; // x20
  __int64 v4; // x8
  unsigned int *v5; // x21
  int v7; // w9
  __int64 v8; // x22
  __int64 v9; // x9
  int v10; // w0
  __int64 v11; // x8
  int v12; // w8
  int v13; // w0
  int v14; // w8
  _DWORD v15[5]; // [xsp+0h] [xbp-20h] BYREF
  int v16; // [xsp+14h] [xbp-Ch]
  __int64 v17; // [xsp+18h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( result )
  {
    if ( a2 )
    {
      v3 = result;
      if ( *(_BYTE *)(result + 2215) == 1 )
      {
        v4 = *(_QWORD *)(result + 31128);
        v5 = *(unsigned int **)(a2 + 128);
        v7 = *(_DWORD *)(result + 2068);
        v16 = 0;
        v8 = *(_QWORD *)(v4 + 384);
        LODWORD(v4) = v7 - 1;
        v9 = v5[28];
        v15[0] = v4;
        v10 = cam_io_r_mb(v8 + v9);
        v11 = v5[26];
        v15[3] = v10;
        v12 = cam_io_r_mb(v8 + v11);
        v13 = a3;
        v15[4] = v12;
        if ( !a3 )
          v13 = cam_io_r_mb(v8 + *v5);
        v14 = *(_DWORD *)(v3 + 2096);
        v15[1] = *(_DWORD *)(v3 + 2080);
        v15[2] = v13;
        LOBYTE(v16) = a3 != 0;
        BYTE1(v16) = v14 != 0;
        result = cam_subdev_notify_message(65544, 8u, (__int64)v15);
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
