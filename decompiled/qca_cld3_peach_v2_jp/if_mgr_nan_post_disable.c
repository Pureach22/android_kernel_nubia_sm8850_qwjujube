__int64 __fastcall if_mgr_nan_post_disable(__int64 a1)
{
  __int64 v1; // x8

  v1 = *(_QWORD *)(a1 + 152);
  if ( v1 )
    return 16 * (unsigned int)(*(_QWORD *)(v1 + 80) == 0);
  else
    return 16;
}
