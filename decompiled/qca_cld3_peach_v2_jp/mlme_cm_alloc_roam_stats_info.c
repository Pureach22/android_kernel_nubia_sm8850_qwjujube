__int64 __fastcall mlme_cm_alloc_roam_stats_info(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x8
  __int64 v10; // x8
  __int64 v11; // x8
  const char *v13; // x2
  unsigned int v14; // w1
  __int64 result; // x0
  __int64 v16; // x8
  unsigned int v17; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v18; // [xsp+8h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(_QWORD *)(a1 + 520);
  v17 = 0;
  if ( !v9 )
  {
    v13 = "%s: vdev legacy private object is NULL";
    goto LABEL_8;
  }
  v10 = *(_QWORD *)(*(_QWORD *)(a1 + 504) + 152LL);
  if ( !v10 || (v11 = *(_QWORD *)(v10 + 80)) == 0 )
  {
    v13 = "%s: Invalid PSOC";
    goto LABEL_8;
  }
  if ( (unsigned int)wlan_mlme_get_roam_info_stats_num(v11, (int *)&v17) )
  {
    v13 = "%s: failed to get groam_info_stats_num";
LABEL_8:
    v14 = 2;
LABEL_9:
    result = qdf_trace_msg(0x68u, v14, v13, a2, a3, a4, a5, a6, a7, a8, a9, "mlme_cm_alloc_roam_stats_info");
    goto LABEL_10;
  }
  if ( !v17 )
  {
    v13 = "%s: groam_info_stats_num = 0, not support enhanced roam";
    goto LABEL_8;
  }
  if ( *(_QWORD *)(*(_QWORD *)(a1 + 520) + 23592LL) )
  {
    v13 = "%s: mlme_priv->enhance_roam_info already malloced";
    v14 = 8;
    goto LABEL_9;
  }
  result = _qdf_mem_malloc(1840LL * v17, "mlme_cm_alloc_roam_stats_info", 4278);
  *(_QWORD *)(*(_QWORD *)(a1 + 520) + 23592LL) = result;
  v16 = *(_QWORD *)(a1 + 520);
  if ( *(_QWORD *)(v16 + 23592) )
  {
    *(_DWORD *)(v16 + 23600) = v17;
    *(_DWORD *)(*(_QWORD *)(a1 + 520) + 23604LL) = 0;
    result = qdf_mutex_create(*(_QWORD *)(a1 + 520) + 23608LL);
  }
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
