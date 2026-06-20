_QWORD *__fastcall mhi_reset_reg_write_q(_QWORD *result)
{
  __int64 v1; // x19

  if ( (*((_BYTE *)result + 340) & 8) == 0 )
  {
    v1 = *(_QWORD *)(result[2] + 192LL);
    cancel_work_sync(v1 + 120);
    result = memset(*(void **)(v1 + 152), 0, 0x2000u);
    *(_QWORD *)(v1 + 160) = 0xFFFFFFFFLL;
  }
  return result;
}
