__int64 __fastcall cam_smmu_cb_qsmmu_component_unbind(__int64 result)
{
  if ( (debug_mdl & 0x40) != 0 && !debug_priority )
    return ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
             3,
             debug_mdl & 0x40,
             4,
             "cam_smmu_cb_qsmmu_component_unbind",
             5732,
             "Unbinding component: %s",
             *(const char **)(result - 16));
  return result;
}
