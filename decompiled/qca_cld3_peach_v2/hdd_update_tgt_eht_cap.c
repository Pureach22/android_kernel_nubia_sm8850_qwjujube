__int64 __fastcall hdd_update_tgt_eht_cap(__int64 a1, _BYTE *a2)
{
  sme_update_tgt_eht_cap(*(_QWORD **)(a1 + 16), a2);
  return mlme_update_tgt_eht_caps_in_cfg(*(_QWORD *)a1, (__int64)a2);
}
