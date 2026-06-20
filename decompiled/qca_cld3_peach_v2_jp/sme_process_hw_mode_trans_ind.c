__int64 __fastcall sme_process_hw_mode_trans_ind(__int64 a1, unsigned int *a2)
{
  return policy_mgr_hw_mode_transition_cb(
           *a2,
           a2[1],
           a2[2],
           (__int64)(a2 + 3),
           a2[11],
           (__int64)(a2 + 12),
           *(_QWORD *)(a1 + 21552));
}
