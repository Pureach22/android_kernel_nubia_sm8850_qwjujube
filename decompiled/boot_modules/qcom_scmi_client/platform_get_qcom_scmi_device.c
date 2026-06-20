__int64 __fastcall platform_get_qcom_scmi_device(unsigned int a1)
{
  __int64 result; // x0
  unsigned __int64 v2; // x8

  if ( a1 > 4 )
    return -22;
  v2 = (unsigned __int64)&qcom_scmi_devices[2 * a1];
  if ( !v2 )
    return -517;
  if ( ((16LL * a1) | 8uLL) > 0x40 )
    goto LABEL_12;
  if ( !*(_DWORD *)(v2 + 8) )
    return -517;
  if ( a1 != 4 )
  {
    result = *(_QWORD *)v2;
    if ( !*(_QWORD *)v2 || !*(_QWORD *)(result + 928) )
      return -19;
    return result;
  }
LABEL_12:
  __break(1u);
  if ( (v2 & 0x2000000000LL) != 0 )
    JUMPOUT(0xFFFFFFFFFFFFF21CLL);
  return get_qcom_scmi_device();
}
