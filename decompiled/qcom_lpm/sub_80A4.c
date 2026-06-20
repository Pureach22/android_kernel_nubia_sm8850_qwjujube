__int64 sub_80A4()
{
  __asm { LDTR            W20, [X17,#0x1C] }
  return _traceiter_cluster_pred_hist();
}
