__int64 __fastcall cam_ife_csid_hw_init(_QWORD *a1, unsigned int a2)
{
  __int64 v3; // x9

  if ( a2 <= 7 )
  {
    v3 = cam_ife_csid_hw_list[a2];
    *a1 = v3;
    if ( v3 )
      return 0;
    else
      return 0xFFFFFFFFLL;
  }
  else
  {
    *a1 = 0;
    return 4294967274LL;
  }
}
