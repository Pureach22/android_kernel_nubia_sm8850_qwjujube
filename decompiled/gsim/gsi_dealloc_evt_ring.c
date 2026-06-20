__int64 __fastcall gsi_dealloc_evt_ring(unsigned __int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x8
  __int64 v6; // x21
  __int64 v7; // x4
  int v8; // w5
  __int64 v9; // x1
  __int64 v10; // x2
  __int64 v11; // x3
  __int64 v12; // x4
  __int64 v13; // x8
  __int64 result; // x0
  unsigned __int64 v15; // x22
  __int64 v16; // x25
  unsigned int v19; // w10
  unsigned __int64 v26; // x10
  unsigned __int64 v29; // x9
  unsigned __int64 v32; // x10
  _QWORD v33[2]; // [xsp+0h] [xbp-10h] BYREF

  v33[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = gsi_ctx;
  v33[0] = 0;
  if ( gsi_ctx )
  {
    if ( a1 > 0x1E || *(unsigned int *)(gsi_ctx + 28612) <= a1 )
    {
      dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d bad params evt_ring_hdl=%lu\n", "gsi_dealloc_evt_ring", 2428, a1);
      result = 4294967290LL;
    }
    else
    {
      v6 = gsi_ctx + 328 * a1 + 18328;
      if ( *(_DWORD *)(gsi_ctx + 328 * a1 + 18636) )
      {
        dev_err(
          *(_QWORD *)(gsi_ctx + 8),
          "%s:%d %d channels still using this event ring\n",
          "gsi_dealloc_evt_ring",
          2436,
          *(_DWORD *)(gsi_ctx + 328 * a1 + 18636));
        if ( gsi_ctx && *(_QWORD *)(gsi_ctx + 28656) )
          result = 4294967289LL;
        else
          result = 4294967289LL;
      }
      else
      {
        v7 = *(unsigned int *)(gsi_ctx + 328 * a1 + 18456);
        if ( (_DWORD)v7 == 1 )
        {
          if ( *(_DWORD *)v6 == 2 && !*(_DWORD *)(gsi_ctx + 328 * a1 + 18332) )
          {
            dev_err(
              *(_QWORD *)(gsi_ctx + 8),
              "%s:%d Interrupt dereg for msi_irq = %d\n",
              "gsi_dealloc_evt_ring",
              2448,
              *(_DWORD *)(gsi_ctx + 328 * a1 + 18368));
            v4 = gsi_ctx;
            if ( *(_DWORD *)(gsi_ctx + 28680) )
            {
              v15 = 0;
              v16 = -24;
              do
              {
                if ( v15 == 2 )
                {
                  __break(0x5512u);
                  if ( !v33 )
                    JUMPOUT(0x1D070);
                  JUMPOUT(0x1DDA8);
                }
                if ( *(_DWORD *)(v4 + v16 + 28736) == *(_DWORD *)(v6 + 36) )
                {
                  mutex_lock(v4 + 28512, a2, a3, a4, v7);
                  _X9 = (unsigned __int64 *)(gsi_ctx + 28696);
                  __asm { PRFM            #0x11, [X9] }
                  do
                    v32 = __ldxr(_X9);
                  while ( __stxr(v32 & ~(1LL << v15), _X9) );
                  *(_DWORD *)(gsi_ctx + 4 * v15 + 28736) = 0;
                  _X8 = (unsigned __int64 *)(gsi_ctx + 28744);
                  __asm { PRFM            #0x11, [X8] }
                  do
                    v29 = __ldxr(_X8);
                  while ( __stxr(v29 & ~(1LL << a1), _X8) );
                  mutex_unlock(gsi_ctx + 28512);
                  v4 = gsi_ctx;
                }
                ++v15;
                v16 += 12;
              }
              while ( v15 < *(unsigned int *)(v4 + 28680) );
            }
          }
          mutex_lock(v4 + 28512, a2, a3, a4, v7);
          *(_DWORD *)(v6 + 256) = 0;
          LODWORD(v33[0]) = 10;
          HIDWORD(v33[0]) = a1;
          ((void (__fastcall *)(__int64, _QWORD, _QWORD *))gsihal_write_reg_n_fields)(
            47,
            *(unsigned int *)(gsi_ctx + 20),
            v33);
          if ( (unsigned int)wait_for_completion_timeout(v6 + 256, 1250) )
          {
            v8 = *(_DWORD *)(v6 + 128);
            if ( v8 )
            {
              dev_err(
                *(_QWORD *)(gsi_ctx + 8),
                "%s:%d evt_id=%lu unexpected state=%u\n",
                "gsi_dealloc_evt_ring",
                2476,
                a1,
                v8);
              __break(0x800u);
            }
            else
            {
              mutex_unlock(gsi_ctx + 28512);
              if ( (*(_BYTE *)(v6 + 112) & 1) == 0 )
              {
                mutex_lock(gsi_ctx + 28512, v9, v10, v11, v12);
                _X9 = (unsigned __int64 *)(gsi_ctx + 28568);
                __asm { PRFM            #0x11, [X9] }
                do
                  v26 = __ldxr(_X9);
                while ( __stxr(v26 & ~(1LL << a1), _X9) );
                mutex_unlock(gsi_ctx + 28512);
              }
              v13 = gsi_ctx;
            }
            _X8 = (unsigned int *)(v13 + 28584);
            __asm { PRFM            #0x11, [X8] }
            do
              v19 = __ldxr(_X8);
            while ( __stxr(v19 - 1, _X8) );
            result = 0;
          }
          else
          {
            dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d evt_id=%lu timed out\n", "gsi_dealloc_evt_ring", 2469, a1);
            mutex_unlock(gsi_ctx + 28512);
            result = 4294967285LL;
          }
        }
        else
        {
          dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d bad state %d\n", "gsi_dealloc_evt_ring", 2441, v7);
          result = 4294967289LL;
        }
      }
    }
  }
  else
  {
    printk(&unk_2DEB9, "gsi_dealloc_evt_ring", 2422);
    result = 4294967288LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
