__int64 __fastcall csr_roam_is_ese_assoc(__int64 a1, unsigned __int8 a2)
{
  return wlan_cm_get_ese_assoc(*(_QWORD *)(a1 + 21560), a2) & 1;
}
