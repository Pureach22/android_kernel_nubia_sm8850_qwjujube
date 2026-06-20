__int64 __fastcall tgt_p2p_mgmt_download_comp_cb(
        __int64 a1,
        __int64 a2,
        char a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  qdf_trace_msg(
    0x4Eu,
    8u,
    "%s: context:%pK, buf:%pK, free:%d",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "tgt_p2p_mgmt_download_comp_cb",
    a1,
    *(_QWORD *)(a2 + 224),
    a3 & 1);
  if ( a2 )
    _qdf_nbuf_free(a2);
  return 0;
}
