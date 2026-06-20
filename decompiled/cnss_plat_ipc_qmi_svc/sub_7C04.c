void sub_7C04()
{
  __int64 v0; // x26
  __int64 v1; // x23
  __int64 v2; // x0

  v1 = *(_QWORD *)(v0 + 80);
  *(_QWORD *)(v0 + 80) = &cnss_plat_ipc_qmi_file_upload_req_handler__alloc_tag;
  v2 = _kmalloc_large_noprof(61460, 3520);
  *(_QWORD *)(v0 + 80) = v1;
  if ( !v2 )
    JUMPOUT(0x7BE0);
  JUMPOUT(0x7A5C);
}
