__int64 __fastcall qdf_check_state_before_panic(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8)
{
  __int64 (*v8)(void); // x8
  __int64 result; // x0
  __int64 (*v10)(void); // x8

  v8 = (__int64 (*)(void))is_recovering_cb;
  if ( !is_recovering_cb )
    goto LABEL_5;
  if ( *((_DWORD *)is_recovering_cb - 1) != 799902358 )
    __break(0x8228u);
  result = v8();
  if ( (result & 1) == 0 )
  {
LABEL_5:
    v10 = (__int64 (*)(void))is_fw_down_cb;
    if ( is_fw_down_cb )
    {
      if ( *((_DWORD *)is_fw_down_cb - 1) != 799902358 )
        __break(0x8228u);
      return v10();
    }
    else
    {
      return qdf_trace_msg(0x38u, 2u, "fw down callback is not registered", a1, a2, a3, a4, a5, a6, a7, a8);
    }
  }
  return result;
}
