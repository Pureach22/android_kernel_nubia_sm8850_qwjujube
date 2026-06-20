__int64 __fastcall stm_char_write(__int64 a1, int a2, size_t a3)
{
  __int64 v4; // x23
  size_t v5; // x20
  _QWORD *v6; // x19
  __int64 v7; // x0
  __int64 v8; // x21
  __int64 v9; // x20
  int policy; // w0
  __int64 v11; // x0
  __int64 v12; // x8
  _QWORD v14[3]; // [xsp+0h] [xbp-30h] BYREF
  _QWORD v15[3]; // [xsp+18h] [xbp-18h] BYREF

  v15[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 32);
  if ( a3 - 4096 >= 0xFFFFFFFFFFFFEFFFLL )
    v5 = a3;
  else
    v5 = 4095;
  v6 = *(_QWORD **)v4;
  if ( *(_DWORD *)(v4 + 20)
    || (v15[0] = 0,
        v15[1] = 0,
        v14[0] = v15,
        v14[1] = "default",
        v14[2] = 0,
        _get_task_comm(v15, 16, _ReadStatusReg(SP_EL0)),
        (policy = stm_assign_first_policy(*(_QWORD *)v4, v4 + 8, v14, 1)) == 0) )
  {
    v7 = _kmalloc_noprof(v5 + 1, 3264);
    v8 = v7;
    if ( v7 )
    {
      if ( v5 >> 31 )
      {
        __break(0x800u);
        v9 = -14;
      }
      else
      {
        _check_object_size(v7, v5, 0);
        if ( (unsigned int)inline_copy_from_user(v8, a2, v5) )
        {
          v9 = -14;
        }
        else
        {
          v11 = _pm_runtime_resume(v6, 4);
          v12 = v6[133];
          if ( v12 )
          {
            v11 = (*(__int64 (__fastcall **)(_QWORD, __int64, _QWORD, __int64, size_t, _QWORD))(v12 + 16))(
                    v6[123],
                    v4 + 8,
                    0,
                    v8,
                    v5,
                    0);
            if ( (v11 & 0x80000000) != 0 )
              v9 = (int)v11;
            else
              v9 = v11 & 0x7FFFFFFF;
          }
          else
          {
            v9 = -19;
          }
          v6[65] = ktime_get_mono_fast_ns(v11);
          _pm_runtime_suspend(v6, 13);
        }
      }
      kfree(v8);
    }
    else
    {
      v9 = -12;
    }
  }
  else
  {
    v9 = policy;
  }
  _ReadStatusReg(SP_EL0);
  return v9;
}
