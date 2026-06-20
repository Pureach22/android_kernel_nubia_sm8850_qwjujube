__int64 __fastcall sub_4FC9C4(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 _X4)
{
  __asm { SUBG            X3, X4, #0x1F0, #0xB }
  return _osif_psoc_sync_op_start(a1, a2, a3);
}
