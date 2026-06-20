__int64 __fastcall zram_req_queue(__int64 *a1)
{
  __int64 v2; // x1
  __int64 (__fastcall *v4)(__int64, __int64, __int64); // x9
  __int64 v5; // x2
  __int64 v6; // x0
  int v7; // w0
  __int64 v8; // x9
  __int64 v9; // x11
  __int64 v10; // x12
  _QWORD *v11; // x8
  int v12; // w10
  int v13; // w9

  if ( comp_control == 127 )
    return 4294967284LL;
  v2 = a1[1];
  v4 = (__int64 (__fastcall *)(__int64, __int64, __int64))off_3E0[0];
  v5 = *((_QWORD *)*off_468 + 5 * *(int *)((char *)&unk_8 + (_QWORD)off_468) + 4);
  v6 = (unsigned int)dword_3D8;
  if ( *((_DWORD *)off_3E0[0] - 1) != 1052847111 )
    __break(0x8229u);
  v7 = v4(v6, v2, v5);
  v8 = a1[3];
  v9 = *a1;
  v10 = a1[1];
  v11 = (_QWORD *)((char *)*off_468 + 40 * v7);
  v11[2] = a1[2];
  v11[3] = v8;
  *v11 = v9;
  v11[1] = v10;
  v12 = *(_DWORD *)((char *)&unk_8 + (_QWORD)off_468);
  ++comp_control;
  if ( v12 == 127 )
    v13 = 0;
  else
    v13 = v12 + 1;
  *(_DWORD *)((char *)&unk_8 + (_QWORD)off_468) = v13;
  raw_spin_lock_irq(&unk_490);
  if ( comp_control == 127 )
  {
    timer_delete(&unk_498);
    if ( byte_3D4 == 1 )
    {
      byte_3D4 = 0;
      complete(&unk_470);
    }
  }
  else if ( (byte_3D4 & 1) == 0 )
  {
    byte_3D4 = 1;
    mod_timer(&unk_498, jiffies + 1LL);
  }
  raw_spin_unlock_irq(&unk_490);
  return 0;
}
