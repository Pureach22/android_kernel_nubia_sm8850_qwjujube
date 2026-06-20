__int64 __fastcall cam_ife_csid_ver2_reset_discard_frame_cfg(__int64 result, __int64 a2, __int64 a3)
{
  __int64 v5; // x19
  __int64 v7; // x8
  unsigned int v13; // w9

  v5 = result;
  _X22 = (unsigned int *)(a2 + 32248);
  *(_WORD *)(a3 + 248) = 0;
  *(_QWORD *)(a3 + 224) = 0;
  while ( 1 )
  {
    __asm { PRFM            #0x11, [X22] }
    do
      v13 = __ldxr(_X22);
    while ( __stxr(v13 - 1, _X22) );
    if ( !*(_DWORD *)(a3 + 216) )
      break;
    v7 = *(unsigned int *)(result + 4);
    if ( (unsigned int)v7 < 0xC )
    {
      result = ((__int64 (__fastcall *)(_QWORD))cam_irq_controller_unsubscribe_irq)(*(_QWORD *)(a2 + 8 * v7 + 31016));
      if ( (_DWORD)result )
        result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                   3,
                   8,
                   2,
                   "cam_ife_csid_ver2_reset_discard_frame_cfg",
                   1142,
                   "CSID[%u] Failed to unsubscribe input SOF for res: %s",
                   *(_DWORD *)(*(_QWORD *)(a2 + 31120) + 4LL),
                   (const char *)(v5 + 128));
      *(_DWORD *)(a3 + 216) = 0;
      break;
    }
    __break(0x5512u);
  }
  if ( (debug_mdl & 8) != 0 && !debug_priority )
    return ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
             3,
             debug_mdl & 8,
             4,
             "cam_ife_csid_ver2_reset_discard_frame_cfg",
             1149,
             "CSID[%u] Reset discard frame config for res: %s discard_ref_cnt: %u",
             *(_DWORD *)(*(_QWORD *)(a2 + 31120) + 4LL),
             (const char *)(v5 + 128),
             *_X22);
  return result;
}
