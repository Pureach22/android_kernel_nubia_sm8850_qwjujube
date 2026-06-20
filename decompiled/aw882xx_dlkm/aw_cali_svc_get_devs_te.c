__int64 __fastcall aw_cali_svc_get_devs_te(__int64 a1, __int64 a2, unsigned int a3)
{
  unsigned int list_head; // w0
  _QWORD *v7; // x25
  unsigned int v8; // w19
  __int64 v9; // x3
  unsigned int te; // w0
  __int64 *v11; // x8
  __int64 v12; // x1
  __int64 *v13; // x8
  __int64 v14; // x1
  void *v15; // x0
  __int64 *v16; // x8
  _QWORD v18[2]; // [xsp+0h] [xbp-10h] BYREF

  v18[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v18[0] = 0;
  list_head = aw882xx_dev_get_list_head(v18);
  if ( list_head )
  {
    v13 = *(__int64 **)(a1 + 112);
    v8 = list_head;
    v14 = v13[14];
    if ( !v14 )
      v14 = *v13;
    v15 = &unk_26C84;
LABEL_19:
    printk(v15, v14, "aw_cali_svc_get_devs_te");
  }
  else
  {
    v7 = *(_QWORD **)v18[0];
    if ( *(_QWORD *)v18[0] != v18[0] )
    {
      v8 = 0;
      while ( 1 )
      {
        v9 = *((unsigned int *)v7 - 293);
        if ( (unsigned int)v9 >= a3 )
        {
          v11 = *(__int64 **)(a1 + 112);
          v12 = v11[14];
          if ( !v12 )
            v12 = *v11;
          printk(&unk_27BF5, v12, "aw_cali_svc_get_devs_te");
        }
        else
        {
          te = aw882xx_dsp_read_te(v7 - 153, a2 + 4 * v9);
          if ( te )
          {
            v8 = te;
            v16 = (__int64 *)*(v7 - 139);
            v14 = v16[14];
            if ( !v14 )
              v14 = *v16;
            v15 = &unk_27FCD;
            goto LABEL_19;
          }
          ++v8;
        }
        v7 = (_QWORD *)*v7;
        if ( v7 == (_QWORD *)v18[0] )
          goto LABEL_20;
      }
    }
    v8 = 0;
  }
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return v8;
}
