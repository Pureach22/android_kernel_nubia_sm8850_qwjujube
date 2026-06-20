__int64 __fastcall sub_1BC34(__int64 a1, __int64 a2)
{
  __int64 v2; // x10
  __int64 v3; // x19

  *(_QWORD *)(v3 - 200) = a2;
  *(_QWORD *)(v3 - 192) = v2;
  return cnss_get_cpumask_for_wlan_tx_comp_interrupts();
}
