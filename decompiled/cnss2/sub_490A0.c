void sub_490A0()
{
  __int64 v0; // x20
  __int64 v1; // x21
  __int64 v2; // x22
  __int64 v3; // x0

  v2 = *(_QWORD *)(v1 + 80);
  *(_QWORD *)(v1 + 80) = &cnss_ims_process_wfc_call_ind_cb__alloc_tag;
  v3 = kmemdup_noprof(v0);
  *(_QWORD *)(v1 + 80) = v2;
  if ( !v3 )
    JUMPOUT(0x49088);
  JUMPOUT(0x49010);
}
