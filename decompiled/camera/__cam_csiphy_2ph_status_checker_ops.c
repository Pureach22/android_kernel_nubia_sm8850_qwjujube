__int64 __fastcall _cam_csiphy_2ph_status_checker_ops(__int64 a1, char a2)
{
  __int64 *v2; // x9
  __int64 v3; // x19
  __int64 v4; // x10
  __int64 v5; // x9
  int v6; // w22
  __int64 v7; // x20
  int v8; // w21
  int v9; // w0
  __int64 v10; // x23
  int v11; // w0
  __int64 v12; // x20
  int v13; // w0
  __int64 v14; // x20
  int v15; // w0

  v2 = *(__int64 **)(a1 + 112);
  v3 = *(_QWORD *)(a1 + 1200);
  v4 = v2[6];
  v5 = *v2;
  if ( (a2 & 1) != 0 )
    v6 = 16;
  else
    v6 = 0;
  v7 = *(unsigned int *)(v4 + 12);
  v8 = *(_DWORD *)(v5 + 24);
  v9 = cam_io_r(v3 + v7);
  cam_io_w_mb(v9 & 0xFFFFFFEF | v6, v3 + v7);
  v10 = (unsigned int)(v8 + v7);
  v11 = cam_io_r(v3 + v10);
  cam_io_w_mb(v11 & 0xFFFFFFEF | v6, v3 + v10);
  v12 = (unsigned int)(v7 + 2 * v8);
  v13 = cam_io_r(v3 + v12);
  cam_io_w_mb(v13 & 0xFFFFFFEF | v6, v3 + v12);
  v14 = (unsigned int)(v12 + v8);
  v15 = cam_io_r(v3 + v14);
  return cam_io_w_mb(v15 & 0xFFFFFFEF | v6, v3 + v14);
}
