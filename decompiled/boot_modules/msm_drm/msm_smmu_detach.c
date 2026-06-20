__int64 __fastcall msm_smmu_detach(__int64 result, __int64 a2)
{
  _QWORD *v2; // x20
  __int64 v3; // x19
  int v4; // w0
  __int64 v5; // x8
  __int64 v6; // x9

  v2 = *(_QWORD **)(result + 40);
  if ( !v2 )
    return printk(&unk_214797, a2);
  if ( *((_BYTE *)v2 + 40) == 1 )
  {
    v3 = result;
    _pm_runtime_resume(*(_QWORD *)(result + 8), 4);
    msm_dma_unmap_all_for_dev(*v2);
    v4 = qcom_iommu_sid_switch(*v2, 1);
    if ( v4 )
      _drm_err("iommu sid switch failed (%d)\n", v4);
    v5 = *v2;
    v6 = *(_QWORD *)(*v2 + 632LL);
    v2[4] = v6;
    if ( v6 )
      *(_QWORD *)(v5 + 632) = 0;
    result = _pm_runtime_idle(*(_QWORD *)(v3 + 8), 4);
    *((_BYTE *)v2 + 40) = 0;
  }
  return result;
}
