_QWORD *__fastcall cds_fill_and_send_ctl_to_fw(
        unsigned int *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  _QWORD *result; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x8
  __int64 v20; // x9
  __int64 v21; // x13
  unsigned __int16 *v22; // x10
  unsigned __int16 *v23; // x11
  const char *v24; // x2
  char v25; // w3
  __int64 v26; // x0

  result = _cds_get_context(54, (__int64)"cds_fill_and_send_ctl_to_fw", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( result )
  {
    v19 = *((_QWORD *)a1 + 2);
    if ( v19 )
    {
      v20 = (unsigned __int16)word_14D34;
      if ( !word_14D34 )
        goto LABEL_13;
      v21 = (unsigned __int16)word_14D34;
      v22 = (unsigned __int16 *)off_14D28;
      v23 = (unsigned __int16 *)off_14D28;
      while ( *v23 != *(unsigned __int16 *)(v19 + 4) )
      {
        --v21;
        v23 += 2;
        if ( !v21 )
          goto LABEL_13;
      }
      if ( v23 )
      {
        while ( *v22 != *(unsigned __int16 *)(v19 + 2) )
        {
          --v20;
          v22 += 2;
          if ( !v20 )
            goto LABEL_18;
        }
        if ( v22 )
        {
          v25 = *((_BYTE *)v23 + 2);
          v26 = *a1;
          *((_BYTE *)a1 + 14) = *((_BYTE *)v22 + 2);
          *((_BYTE *)a1 + 13) = v25;
          return (_QWORD *)wma_send_regdomain_info_to_fw(
                             v26,
                             *(unsigned __int16 *)(v19 + 4),
                             *(unsigned __int16 *)(v19 + 2));
        }
LABEL_18:
        v24 = "%s: failed to get regdmn 5G";
      }
      else
      {
LABEL_13:
        v24 = "%s: failed to get regdmn 2G";
      }
      return (_QWORD *)qdf_trace_msg(
                         0x38u,
                         2u,
                         v24,
                         v11,
                         v12,
                         v13,
                         v14,
                         v15,
                         v16,
                         v17,
                         v18,
                         "cds_fill_and_send_ctl_to_fw");
    }
    else
    {
      return (_QWORD *)qdf_trace_msg(
                         0x38u,
                         2u,
                         "%s: %s: no regpair is found, can not proceed",
                         v11,
                         v12,
                         v13,
                         v14,
                         v15,
                         v16,
                         v17,
                         v18,
                         "cds_fill_and_send_ctl_to_fw",
                         "cds_fill_and_send_ctl_to_fw");
    }
  }
  return result;
}
