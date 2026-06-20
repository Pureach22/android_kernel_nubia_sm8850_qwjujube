__int64 __fastcall ath_procfs_diag_write(__int64 a1, const void *a2, size_t a3, unsigned int *a4)
{
  __int64 v5; // x0
  unsigned __int64 v6; // x21
  unsigned int (*v7)(void); // x8
  unsigned __int64 v12; // x23
  __int64 v13; // x25
  __int64 v14; // x0
  __int64 v15; // x20
  __int64 v16; // x21
  __int64 v17; // x0
  _DWORD *v18; // x20
  __int64 target_info_handle; // x0
  int v20; // w4
  unsigned int v21; // w4
  __int64 v22; // x22
  __int64 v23; // x0
  int v24; // w8
  int v25; // w8
  unsigned int v26; // w8
  unsigned int v27; // w23
  unsigned int v28; // w22
  int v29; // w0
  __int64 v30; // x1
  int v31; // w21

  v5 = *(_QWORD *)(*(_QWORD *)(a1 + 40) + 696LL);
  if ( !v5 )
    return -22;
  v6 = *(_QWORD *)a4;
  v7 = *(unsigned int (**)(void))(v5 + 392);
  if ( *((_DWORD *)v7 - 1) != -174160978 )
    __break(0x8228u);
  if ( v7() | v6 & 3 )
    return -22;
  v12 = v6 >> 60;
  qdf_trace_msg(
    61,
    8,
    "%s: wr cnt %zu offset 0x%x op_type %d mem_type %d",
    "ath_procfs_diag_write",
    a3,
    v6,
    v6 >> 60,
    (unsigned __int8)(v6 >> 52));
  if ( (v6 >> 60) - 1 < 2 )
  {
    v13 = *(_QWORD *)(*(_QWORD *)(a1 + 40) + 696LL);
    if ( v13 )
    {
      v14 = _qdf_mem_malloc(a3, "ath_procfs_diag_write_ext", 433);
      if ( v14 )
      {
        v15 = v14;
        if ( a3 >> 31 )
        {
          __break(0x800u);
          goto LABEL_12;
        }
        _check_object_size(v14, a3, 0);
        if ( inline_copy_from_user(v15, (int)a2, a3) )
        {
LABEL_12:
          _qdf_mem_free(v15);
          qdf_trace_msg(61, 2, "%s: copy_to_user error in /proc/%s", "ath_procfs_diag_write_ext", "athdiagpfs");
          return -14;
        }
        target_info_handle = hif_get_target_info_handle(v13);
        v20 = *(_DWORD *)(v13 + 72);
        if ( v20 != 6 && v20 )
        {
          qdf_trace_msg(61, 2, "%s: Unrecognized bus type %d", "ath_procfs_diag_write_ext");
        }
        else
        {
          v21 = *(_DWORD *)(target_info_handle + 4);
          if ( v21 <= 0x2B && ((1LL << v21) & 0xD6488800000LL) != 0 )
          {
            v22 = -5;
            if ( (_DWORD)v12 != 2
              && !(unsigned int)pld_athdiag_write(
                                  *(_QWORD *)(*(_QWORD *)(v13 + 576) + 40LL),
                                  (unsigned int)v6,
                                  (unsigned __int8)(v6 >> 52),
                                  (unsigned int)a3,
                                  v15) )
            {
              v22 = a3;
            }
            goto LABEL_40;
          }
          qdf_trace_msg(61, 2, "%s: Unrecognized target type %d", "ath_procfs_diag_write_ext");
        }
        v22 = -5;
LABEL_40:
        _qdf_mem_free(v15);
        return v22;
      }
      return -12;
    }
    return -22;
  }
  if ( (_DWORD)v12 )
  {
    qdf_trace_msg(61, 2, "%s: Unrecognized op type %d", "ath_procfs_diag_write", v12);
    return -22;
  }
  v16 = *(_QWORD *)(*(_QWORD *)(a1 + 40) + 696LL);
  v17 = _qdf_mem_malloc(a3, "ath_procfs_diag_write_legacy", 185);
  if ( !v17 )
    return -12;
  v18 = (_DWORD *)v17;
  if ( a3 >> 31 )
  {
    __break(0x800u);
    goto LABEL_17;
  }
  _check_object_size(v17, a3, 0);
  if ( inline_copy_from_user((int)v18, (int)a2, a3) )
  {
LABEL_17:
    _qdf_mem_free(v18);
    qdf_trace_msg(61, 2, "%s: copy_to_user error in /proc/%s", "ath_procfs_diag_write_legacy", "athdiagpfs");
    return -14;
  }
  qdf_trace_msg(
    61,
    8,
    "%s: wr buff 0x%pK buf 0x%pK cnt %zu offset 0x%x value 0x%x",
    "ath_procfs_diag_write_legacy",
    v18,
    a2,
    a3,
    *a4,
    *v18);
  v23 = hif_get_target_info_handle(v16);
  v24 = *(_DWORD *)(v16 + 72);
  if ( v24 > 4 )
  {
    if ( v24 == 5 )
    {
      if ( *(_DWORD *)(v23 + 4) == 22 )
        goto LABEL_43;
    }
    else if ( v24 == 6 )
    {
      v25 = *(_DWORD *)(v23 + 4);
      if ( v25 == 28 || v25 == 40 )
        goto LABEL_43;
    }
LABEL_45:
    v30 = *a4;
    if ( a3 != 4 || (v30 & 3) != 0 )
      v29 = hif_diag_write_mem(v16, v30, v18, (unsigned int)a3);
    else
      v29 = hif_diag_write_access(v16);
    goto LABEL_49;
  }
  if ( !v24 )
  {
    v26 = *(_DWORD *)(v23 + 4);
    if ( v26 <= 0x2B && ((1LL << v26) & 0xEBFEFF00000LL) != 0 )
      goto LABEL_43;
    goto LABEL_45;
  }
  if ( v24 != 2 )
    goto LABEL_45;
LABEL_43:
  v27 = *a4;
  v28 = HIBYTE(*a4);
  qdf_trace_msg(
    61,
    8,
    "%s: offset 0x%x memtype 0x%x, datalen %zu",
    "ath_procfs_diag_write_legacy",
    *a4 & 0xFFFFFF,
    v28,
    a3);
  v29 = pld_athdiag_write(*(_QWORD *)(*(_QWORD *)(v16 + 576) + 40LL), v27 & 0xFFFFFF, v28, (unsigned int)a3, v18);
LABEL_49:
  v31 = v29;
  _qdf_mem_free(v18);
  if ( v31 )
    return -5;
  else
    return a3;
}
