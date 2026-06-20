__int64 __fastcall msm_hw_fence_wait_update(unsigned int *a1, __int64 a2, int a3)
{
  __int64 v3; // x30
  __int64 v7; // x23
  int v8; // w19
  _QWORD *v9; // x24
  unsigned int updated; // w0
  __int64 v11; // x2
  __int64 v12; // x3
  __int64 v13; // x4
  unsigned int v14; // w0
  __int64 result; // x0
  unsigned int v16; // w8
  __int64 v17; // x4
  unsigned int v18; // w8
  __int64 v19; // x4
  unsigned int v20; // w19
  unsigned int v21; // w19
  unsigned __int64 v22[2]; // [xsp+10h] [xbp-10h] BYREF

  v22[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a3 )
  {
    v7 = v3;
    v8 = 0;
    v22[0] = 0;
    while ( 1 )
    {
      v9 = (_QWORD *)(a2 + 8LL * v8);
      updated = msm_hw_fence_wait_update_v2((unsigned __int64)a1, v9, (__int64)v22, 0, 1);
      if ( updated )
        break;
      v14 = msm_hw_fence_destroy_with_handle(a1, v22[0], v11, v12, v13);
      if ( v14 )
      {
        if ( *v9 )
        {
          v19 = *(_QWORD *)(*v9 + 32LL);
          v18 = v14;
        }
        else
        {
          v18 = v14;
          v19 = -1;
        }
        v21 = v18;
        printk(&unk_2AA88, "msm_hw_fence_wait_update", 509, v7, v19);
        result = v21;
        goto LABEL_7;
      }
      if ( a3 == ++v8 )
        goto LABEL_6;
    }
    if ( *v9 )
    {
      v17 = *(_QWORD *)(*v9 + 32LL);
      v16 = updated;
    }
    else
    {
      v16 = updated;
      v17 = -1;
    }
    v20 = v16;
    printk(&unk_2415E, "msm_hw_fence_wait_update", 500, v7, v17);
    result = v20;
  }
  else
  {
LABEL_6:
    result = 0;
  }
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
