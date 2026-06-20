__int64 __fastcall mlo_unreg_mlme_ext_cb(__int64 a1)
{
  if ( !a1 )
    return 16;
  *(_QWORD *)(a1 + 352) = 0;
  return 0;
}
