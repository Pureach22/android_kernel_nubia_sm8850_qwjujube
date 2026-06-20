void sub_3F72C()
{
  unsigned int v0; // w22
  __int64 v1; // x23
  __int64 v2; // x21

  v2 = *(_QWORD *)(v1 + 80);
  *(_QWORD *)(v1 + 80) = &cnss_wlfw_qdss_data_send_sync__alloc_tag_112;
  vzalloc_noprof(v0);
  *(_QWORD *)(v1 + 80) = v2;
  JUMPOUT(0x3F020);
}
