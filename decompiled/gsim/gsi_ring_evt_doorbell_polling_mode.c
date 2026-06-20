__int64 __fastcall gsi_ring_evt_doorbell_polling_mode(unsigned __int64 a1)
{
  __int64 v1; // x8
  __int64 v2; // x9
  __int64 v3; // x2

  if ( a1 >= 0x24 )
  {
    __break(0x5512u);
    return gsi_complete_clk_grant();
  }
  else
  {
    v1 = gsi_ctx;
    v2 = *(_QWORD *)(gsi_ctx + 448 * a1 + 392);
    v3 = *(unsigned __int8 *)(v2 + 132);
    *(_QWORD *)(v2 + 160) = *(_QWORD *)(v2 + 176);
    return gsihal_write_reg_nk(17, *(unsigned int *)(v1 + 20), v3);
  }
}
