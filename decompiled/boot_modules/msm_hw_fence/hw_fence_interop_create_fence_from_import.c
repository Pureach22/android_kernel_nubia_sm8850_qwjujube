__int64 __fastcall hw_fence_interop_create_fence_from_import(unsigned __int64 a1)
{
  __int64 v1; // x30
  _QWORD *v3; // x19
  __int64 v4; // x20
  __int64 (__fastcall *v5)(_QWORD); // x8
  __int64 v6; // x0
  __int64 v7; // x22
  __int64 v8; // x24
  __int64 v9; // x3
  __int64 v10; // x4
  int v11; // w8
  unsigned int v12; // w0
  int v13; // w0
  __int64 result; // x0
  unsigned int *v15; // x4
  unsigned __int64 v16; // x22
  __int64 (__fastcall *v17)(unsigned __int64, __int64, unsigned int *); // x5
  __int64 v18; // x1
  int v19; // w0
  unsigned int v20; // w23
  int v21; // w0
  int updated; // w23
  unsigned __int64 v23; // x4
  __int64 v24; // x30
  int v25; // w0
  unsigned int v26; // w19
  unsigned int v27; // w0
  __int64 v28; // x30
  unsigned int v29; // w20
  int v30; // w6
  void *v31; // x0
  __int64 v32; // x2
  __int64 v33; // x30
  int v34; // w21
  int v35; // w21
  unsigned __int64 v42; // x9
  unsigned __int64 v45; // x9
  unsigned __int64 v46; // [xsp+10h] [xbp-100h] BYREF
  unsigned int v47; // [xsp+1Ch] [xbp-F4h] BYREF
  _QWORD v48[30]; // [xsp+20h] [xbp-F0h] BYREF

  v48[29] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v48, 0, 232);
  v46 = 0;
  if ( !a1
    || a1 > 0xFFFFFFFFFFFFF000LL
    || (v3 = *(_QWORD **)(a1 + 16)) == nullptr
    || (unsigned __int64)v3 >= 0xFFFFFFFFFFFFF001LL )
  {
    printk(&unk_23D8B, "hw_fence_interop_create_fence_from_import", 214, v1, a1);
    result = 4294967274LL;
    goto LABEL_44;
  }
  if ( (v3[6] & 1) != 0 )
    goto LABEL_11;
  v4 = v1;
  v5 = *(__int64 (__fastcall **)(_QWORD))(v3[1] + 32LL);
  if ( !v5 )
    goto LABEL_12;
  v6 = *(_QWORD *)(a1 + 16);
  if ( *((_DWORD *)v5 - 1) != 1879296680 )
    __break(0x8228u);
  if ( (v5(v6) & 1) == 0 )
  {
LABEL_12:
    v7 = raw_spin_lock_irqsave(*v3);
    if ( (v3[6] & 0x80000000) != 0 )
    {
      raw_spin_unlock_irqrestore(*v3, v7);
      result = 0;
      goto LABEL_44;
    }
    v8 = v3[6];
    v9 = v3[4];
    v10 = v3[5];
    if ( (v8 & 0x20000000) != 0 )
      v11 = -2;
    else
      v11 = -3;
    LODWORD(v48[0]) = v11;
    v12 = hw_fence_create(hw_fence_drv_data, (__int64)v48, (__int64)v3, v9, v10, (__int64 *)&v46);
    if ( v12 )
    {
      v28 = v4;
      v29 = v12;
      printk(&unk_24758, "hw_fence_interop_create_fence_from_import", 245, v28, LODWORD(v48[0]));
      raw_spin_unlock_irqrestore(*v3, v7);
      goto LABEL_48;
    }
    _X8 = v3 + 6;
    __asm { PRFM            #0x11, [X8] }
    do
      v45 = __ldxr(_X8);
    while ( __stxr(v45 | 0x80000000, _X8) );
    raw_spin_unlock_irqrestore(*v3, v7);
    if ( (v8 & 0x20000000) != 0 )
    {
      v15 = *(unsigned int **)a1;
      v16 = v46;
      v17 = (__int64 (__fastcall *)(unsigned __int64, __int64, unsigned int *))synx_interops;
      v47 = 0;
      if ( v15 && synx_interops )
      {
        v18 = (unsigned int)v46;
        if ( *((_DWORD *)synx_interops - 1) != 1500435254 )
          __break(0x8225u);
        v19 = v17(a1, v18, &v47);
        if ( v19 || !v47 )
        {
          v34 = v19;
          printk(&unk_23523, "_update_interop_fence", 179, v4, v16);
          hw_fence_destroy_refcount(hw_fence_drv_data, v16, 0x80000000);
          v13 = v34;
        }
        else
        {
          switch ( v47 )
          {
            case 1u:
              goto LABEL_37;
            case 2u:
              v20 = 0;
              break;
            case 6u:
              v20 = 1;
              break;
            default:
              v20 = v47;
              break;
          }
          if ( (~msm_hw_fence_debug_level & 0x10002) == 0 )
            printk(&unk_294E6, "hw_fence_interop_to_hw_fence_error", 121, v47, v20);
          v21 = hw_fence_signal_fence(hw_fence_drv_data, 0, v16, v20, 1);
          if ( v21 )
          {
            v35 = v21;
            printk(&unk_258BE, "_update_interop_fence", 189, v4, v16);
            v13 = v35;
          }
          else
          {
LABEL_37:
            updated = hw_fence_update_hsynx(hw_fence_drv_data, v16, **(_DWORD **)a1, 0);
            v13 = 0;
            if ( updated )
            {
              printk(&unk_2590A, "_update_interop_fence", 198, v4, v16);
              v13 = updated;
            }
          }
        }
      }
      else
      {
        printk(&unk_2956B, "_update_interop_fence", 172, v4, v15);
        v13 = -22;
      }
    }
    else
    {
      v13 = hw_fence_destroy_refcount(hw_fence_drv_data, v46, 0x80000000);
    }
    v23 = v46;
    v24 = v4;
    if ( v13 )
    {
      v30 = v13;
      v31 = &unk_2A60F;
      v32 = 261;
    }
    else
    {
      v25 = hw_fence_add_callback(hw_fence_drv_data, v3, v46);
      if ( !v25 )
      {
        v26 = 0;
LABEL_42:
        v27 = hw_fence_destroy_with_hash(hw_fence_drv_data, (unsigned int *)v48, v46);
        if ( !v27 )
        {
          result = v26;
          goto LABEL_44;
        }
        v33 = v4;
        v29 = v27;
        printk(&unk_24CEF, "hw_fence_interop_create_fence_from_import", 276, v33, LODWORD(v48[0]));
LABEL_48:
        result = v29;
        goto LABEL_44;
      }
      v24 = v4;
      v23 = v46;
      v30 = v25;
      v32 = 268;
      v31 = &unk_20722;
    }
    v26 = v30;
    printk(v31, "hw_fence_interop_create_fence_from_import", v32, v24, v23);
    goto LABEL_42;
  }
  dma_fence_signal(v3);
LABEL_11:
  _X8 = v3 + 6;
  __asm { PRFM            #0x11, [X8] }
  do
    v42 = __ldxr(_X8);
  while ( __stxr(v42 | 0x80000000, _X8) );
  result = 0;
LABEL_44:
  _ReadStatusReg(SP_EL0);
  return result;
}
