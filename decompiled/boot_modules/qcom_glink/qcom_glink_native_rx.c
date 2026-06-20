__int64 __fastcall qcom_glink_native_rx(__int64 a1)
{
  __int64 (*v2)(void); // x8
  __int64 result; // x0
  int v4; // w25
  void (*v5)(void); // x8
  __int64 (*v6)(void); // x8

  _ReadStatusReg(SP_EL0);
  if ( should_wake == 1 )
  {
    should_wake = 0;
    glink_resume_pkt = 1;
    pm_system_wakeup();
  }
  _wake_up(a1 + 224, 3, 0, 0);
  v2 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 16) + 8LL);
  if ( *((_DWORD *)v2 - 1) != -1056647900 )
    __break(0x8228u);
  result = v2();
  if ( (unsigned int)result >= 8uLL )
  {
    v4 = 0;
    _ReadStatusReg(SP_EL0);
    do
    {
      v5 = *(void (**)(void))(*(_QWORD *)(a1 + 16) + 16LL);
      if ( *((_DWORD *)v5 - 1) != -396915495 )
        __break(0x8228u);
      v5();
      result = qcom_glink_rx_defer(a1, 0);
      if ( (_DWORD)result )
        break;
      ++v4;
      v6 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 16) + 8LL);
      if ( *((_DWORD *)v6 - 1) != -1056647900 )
        __break(0x8228u);
      result = v6();
    }
    while ( (unsigned int)result > 7uLL );
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
