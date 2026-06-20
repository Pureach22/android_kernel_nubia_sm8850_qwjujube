_QWORD *__fastcall cam_smmu_fw_dev_component_unbind(__int64 a1)
{
  _QWORD *result; // x0

  if ( mem_trace_en == 1 )
    result = cam_mem_trace_free((_QWORD *)icp_fw, 0);
  else
    result = (_QWORD *)kvfree(icp_fw);
  icp_fw = 0;
  if ( (debug_mdl & 0x40) != 0 && !debug_priority )
    return (_QWORD *)((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                       3,
                       debug_mdl & 0x40,
                       4,
                       "cam_smmu_fw_dev_component_unbind",
                       5661,
                       "Unbinding component: %s",
                       *(const char **)(a1 - 16));
  return result;
}
