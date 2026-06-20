void *__fastcall lim_defer_sme_indication(
        __int64 a1,
        __int64 a2,
        char a3,
        const void *a4,
        __int64 a5,
        char a6,
        char a7,
        char a8,
        __int16 a9)
{
  __int64 v16; // x21
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x27
  __int64 v26; // x8
  __int64 v27; // x8
  __int64 v28; // x8
  void *result; // x0
  __int64 v30; // [xsp+8h] [xbp-8h]

  v16 = lim_search_pre_auth_list(a1, a4);
  if ( *(_BYTE *)(v16 + 560) == 1 )
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Free the cached assoc req as a new one is received",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "lim_defer_sme_indication");
    v25 = *(_QWORD *)(v16 + 584);
    if ( *(_BYTE *)(v16 + 577) == 1 && v25 && (v26 = *(_QWORD *)(a2 + 384)) != 0 )
    {
      *(_QWORD *)(v26 + 8LL * *(unsigned __int16 *)(v25 + 336)) = 0;
    }
    else if ( !v25 )
    {
LABEL_11:
      lim_free_assoc_req_frm_buf(*(_QWORD *)(v16 + 568));
      _qdf_mem_free(*(_QWORD *)(v16 + 568));
      goto LABEL_12;
    }
    if ( *(_DWORD *)(v25 + 8) != 21 )
    {
      v27 = *(_QWORD *)(a2 + 384);
      if ( v27 )
      {
        v28 = *(_QWORD *)(v27 + 8LL * *(unsigned __int16 *)(v25 + 336));
        if ( v28 )
        {
          v30 = v28;
          lim_free_assoc_req_frm_buf(v28);
          _qdf_mem_free(v30);
          *(_QWORD *)(*(_QWORD *)(a2 + 384) + 8LL * *(unsigned __int16 *)(v25 + 336)) = 0;
        }
      }
    }
    goto LABEL_11;
  }
LABEL_12:
  *(_BYTE *)(v16 + 560) = 1;
  *(_BYTE *)(v16 + 561) = a3;
  result = qdf_mem_copy((void *)(v16 + 562), a4, 6u);
  *(_QWORD *)(v16 + 568) = a5;
  *(_BYTE *)(v16 + 576) = a6 & 1;
  *(_BYTE *)(v16 + 577) = a7 & 1;
  *(_BYTE *)(v16 + 578) = a8 & 1;
  *(_QWORD *)(v16 + 584) = 0;
  *(_WORD *)(v16 + 592) = a9;
  return result;
}
