__int64 __fastcall cam_vfe_top_ver4_read_hw_query(__int64 a1, _QWORD *a2)
{
  unsigned int *v2; // x20
  __int64 v3; // x21
  __int64 v5; // x8
  __int64 v6; // x8
  __int64 v7; // x8
  __int64 v8; // x8
  __int64 v9; // x8

  v2 = (unsigned int *)a2[31];
  v3 = *(_QWORD *)(a1 + 288);
  cam_io_w(v2[5], v3 + v2[1]);
  cam_io_w(v2[7] + v2[6] * v2[10], v3 + *v2);
  if ( (v2[4] & (unsigned int)cam_io_r(v3 + v2[2])) != 0 )
    v5 = v2[3] & (unsigned int)cam_io_r(v3 + v2[2]);
  else
    v5 = -1;
  a2[32] = v5;
  cam_io_w(v2[7] + v2[6] * v2[11], v3 + *v2);
  if ( (v2[4] & (unsigned int)cam_io_r(v3 + v2[2])) != 0 )
    v6 = v2[3] & (unsigned int)cam_io_r(v3 + v2[2]);
  else
    v6 = -1;
  a2[33] = v6;
  cam_io_w(v2[9] + v2[8] * v2[13], v3 + *v2);
  if ( (v2[4] & (unsigned int)cam_io_r(v3 + v2[2])) != 0 )
    v7 = v2[3] & (unsigned int)cam_io_r(v3 + v2[2]);
  else
    v7 = -1;
  a2[35] = v7;
  cam_io_w(v2[9] + v2[8] * v2[14], v3 + *v2);
  if ( (v2[4] & (unsigned int)cam_io_r(v3 + v2[2])) != 0 )
    v8 = v2[3] & (unsigned int)cam_io_r(v3 + v2[2]);
  else
    v8 = -1;
  a2[34] = v8;
  cam_io_w(v2[9] + v2[8] * v2[12], v3 + *v2);
  if ( (v2[4] & (unsigned int)cam_io_r(v3 + v2[2])) != 0 )
    v9 = v2[3] & (unsigned int)cam_io_r(v3 + v2[2]);
  else
    v9 = -1;
  a2[36] = v9;
  return 0;
}
