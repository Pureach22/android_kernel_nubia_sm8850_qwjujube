__int64 __fastcall ipa_fltrt_get_aligned_lcl_bdy_size(__int64 a1, int a2)
{
  unsigned int v2; // w8
  _DWORD *v3; // x22
  int v5; // w20
  unsigned int v6; // w21
  __int64 ipc_logbuf_low; // x0

  v2 = *(_DWORD *)ipahal_ctx;
  if ( *(_DWORD *)ipahal_ctx >= 0x1Bu )
    goto LABEL_8;
  if ( ((152LL * v2) | 4uLL) > 0xF70 || v2 == 26 )
  {
    __break(1u);
LABEL_8:
    __break(0x5512u);
    return ipahal_fltrt_allocate_hw_tbl_imgs(a1);
  }
  v3 = (_DWORD *)((char *)&ipahal_fltrt_objs + 152 * v2);
  v5 = a1;
  v6 = (v3[4] + a2 + (v3[3] + v3[1]) * a1) & ~v3[4];
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    ipc_log_string(
      ipc_logbuf_low,
      "ipahal %s:%d num_lcl_tbls = %u total_sz_lcl_tbls = %u tbl_width = %u lcladdr_alignment = %u blk_sz_alignment = %u result = %u\n",
      "ipa_fltrt_get_aligned_lcl_bdy_size",
      5126,
      v5,
      a2,
      v3[1],
      v3[3],
      v3[4],
      v6);
  }
  return v6;
}
