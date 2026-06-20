__int64 __fastcall sub_6B67C(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6, __int64 a7)
{
  int v7; // w21

  return msm_v4l2_create_bufs(a1, a2, a3, a4, a5, a6, a7, v7 ^ (unsigned int)((int)a1 >> 4));
}
