__int64 __fastcall adreno_unbind(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x20
  __int64 v3; // x21
  void (__fastcall *v4)(_QWORD); // x8
  unsigned __int64 v5; // x0
  unsigned __int64 v6; // x0
  unsigned __int64 v7; // x0
  void (__fastcall **v8)(_QWORD); // x8
  void (__fastcall *v9)(_QWORD); // x8
  int v10; // w8
  unsigned __int64 v17; // x10
  unsigned __int64 v20; // x10

  v1 = *(_QWORD *)(result + 152);
  if ( v1 && *(_QWORD *)(v1 + 11168) )
  {
    v2 = result;
    if ( *(_BYTE *)(v1 + 13417) == 1 )
    {
      cleanup_srcu_struct(v1 + 13912);
      *(_BYTE *)(v1 + 13417) = 0;
    }
    v3 = *(_QWORD *)(*(_QWORD *)(v1 + 14264) + 40LL);
    trace_array_put(*(_QWORD *)(v1 + 13408));
    v4 = *(void (__fastcall **)(_QWORD))(v3 + 40);
    if ( v4 )
    {
      if ( *((_DWORD *)v4 - 1) != 994519391 )
        __break(0x8228u);
      v4(v1);
    }
    if ( adreno_input_handler )
      input_unregister_handler(&adreno_input_handler);
    kgsl_qcom_va_md_unregister(v1);
    adreno_coresight_remove(v1);
    adreno_profile_close(v1);
    v5 = *(_QWORD *)(v1 + 20824);
    if ( v5 && v5 <= 0xFFFFFFFFFFFFF000LL )
      llcc_slice_putd(v5);
    v6 = *(_QWORD *)(v1 + 20840);
    if ( v6 && v6 <= 0xFFFFFFFFFFFFF000LL )
      llcc_slice_putd(v6);
    v7 = *(_QWORD *)(v1 + 20856);
    if ( v7 && v7 <= 0xFFFFFFFFFFFFF000LL )
      llcc_slice_putd(v7);
    kgsl_pwrscale_close(v1);
    v8 = *(void (__fastcall ***)(_QWORD))(v1 + 20896);
    if ( v8 )
    {
      v9 = *v8;
      if ( v9 )
      {
        if ( *((_DWORD *)v9 - 1) != 994519391 )
          __break(0x8228u);
        v9(v1);
      }
    }
    kgsl_device_platform_remove(v1);
    component_unbind_all(v2, 0);
    result = kgsl_bus_close(v1);
    v10 = *(_DWORD *)(v1 + 13100);
    *(_QWORD *)(v1 + 11168) = 0;
    if ( v10 )
      result = qcom_dcvs_unregister_voter("kgsl-l3", 2, 0);
    _X8 = (unsigned __int64 *)(v1 + 14240);
    __asm { PRFM            #0x11, [X8] }
    do
      v17 = __ldxr(_X8);
    while ( __stxr(v17 & 0xFFFFFFFFFFFFFFFDLL, _X8) );
    _X8 = (unsigned __int64 *)(v1 + 14240);
    __asm { PRFM            #0x11, [X8] }
    do
      v20 = __ldxr(_X8);
    while ( __stxr(v20 & 0xFFFFFFFFFFFFFFFBLL, _X8) );
  }
  return result;
}
