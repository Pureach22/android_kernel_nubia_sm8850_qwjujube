__int64 __fastcall server_del(__int64 a1, unsigned int a2, char a3)
{
  __int64 v3; // x22
  __int64 result; // x0
  _DWORD *v7; // x19
  int v8; // w9
  unsigned int v9; // w0
  unsigned int v10; // w20
  __int64 v11; // x3
  __int64 v12; // x4
  __int64 v13; // x5
  __int64 v14; // x6
  __int64 v15; // x7
  __int64 *i; // x25
  int v17; // w8
  int v18; // w9
  int v19; // w8
  int v20; // w8
  unsigned int v21; // w0
  unsigned int v22; // w23
  __int64 v23; // x3
  __int64 v24; // x4
  __int64 v25; // x5
  __int64 v26; // x6
  __int64 v27; // x7
  int *v28; // [xsp+8h] [xbp-98h] BYREF
  __int64 v29; // [xsp+10h] [xbp-90h]
  __int16 *v30; // [xsp+18h] [xbp-88h] BYREF
  __int64 v31; // [xsp+20h] [xbp-80h]
  __int64 v32; // [xsp+28h] [xbp-78h]
  __int64 v33; // [xsp+30h] [xbp-70h]
  __int64 v34; // [xsp+38h] [xbp-68h]
  __int64 v35; // [xsp+40h] [xbp-60h]
  __int64 v36; // [xsp+48h] [xbp-58h]
  __int64 v37; // [xsp+50h] [xbp-50h]
  __int64 v38; // [xsp+58h] [xbp-48h]
  __int64 v39; // [xsp+60h] [xbp-40h]
  __int64 v40; // [xsp+68h] [xbp-38h]
  __int64 v41; // [xsp+70h] [xbp-30h]
  __int64 v42; // [xsp+78h] [xbp-28h]
  int v43; // [xsp+84h] [xbp-1Ch] BYREF
  int v44; // [xsp+88h] [xbp-18h]
  int v45; // [xsp+8Ch] [xbp-14h]
  int v46; // [xsp+90h] [xbp-10h]
  int v47; // [xsp+94h] [xbp-Ch]
  __int64 v48; // [xsp+98h] [xbp-8h]

  v3 = a2;
  v48 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = xa_load(a1 + 8, a2);
  if ( result )
  {
    v7 = (_DWORD *)result;
    xa_erase(a1 + 8, v3);
    if ( v7[2] == dword_D9F8 && (a3 & 1) != 0 )
    {
      v41 = 0;
      v42 = 0;
      v39 = 0;
      v40 = 0;
      v37 = 0;
      v38 = 0;
      v35 = 0;
      v36 = 0;
      v33 = 0;
      v34 = 0;
      v31 = 0;
      v32 = 0;
      ipc_log_string(ns_ilc, "%s: [0x%x:0x%x]@[0x%x:0x%x]\n", "service_announce_del", *v7, v7[1], v7[2], v7[3]);
      v28 = &v43;
      v29 = 20;
      v43 = 5;
      v44 = *v7;
      v45 = v7[1];
      v46 = v7[2];
      v8 = v7[3];
      v30 = &word_D970;
      v47 = v8;
      LODWORD(v31) = 12;
      v9 = kernel_sendmsg(qrtr_ns, &v30, &v28, 1, 20);
      if ( (v9 & 0x80000000) != 0 )
      {
        v10 = v9;
        if ( v9 != -19 )
        {
          if ( (unsigned int)__ratelimit(&service_announce_del__rs, "service_announce_del") )
            printk(&unk_DD27, "service_announce_del", v10, v11, v12, v13, v14, v15);
        }
      }
    }
    for ( i = (__int64 *)qword_D980; i != &qword_D980; i = (__int64 *)*i )
    {
      v17 = *((_DWORD *)i - 6);
      if ( !v17 || v17 == *v7 )
      {
        v18 = *((_DWORD *)i - 5);
        v19 = v7[1];
        if ( !v18 || v18 == v19 )
        {
          v41 = 0;
          v42 = 0;
          v39 = 0;
          v40 = 0;
          v37 = 0;
          v38 = 0;
          v35 = 0;
          v36 = 0;
          v33 = 0;
          v34 = 0;
          v31 = 0;
          v32 = 0;
          v28 = &v43;
          v29 = 20;
          v43 = 5;
          v44 = *v7;
          v45 = v19;
          v20 = v7[2];
          v30 = (__int16 *)(i - 2);
          LODWORD(v31) = 12;
          v46 = v20;
          v47 = v7[3];
          v21 = kernel_sendmsg(qrtr_ns, &v30, &v28, 1, 20);
          if ( (v21 & 0x80000000) != 0 )
          {
            v22 = v21;
            if ( v21 != -19 )
            {
              if ( (unsigned int)__ratelimit(&lookup_notify__rs, "lookup_notify") )
                printk(&unk_E226, "lookup_notify", v22, v23, v24, v25, v26, v27);
            }
          }
        }
      }
    }
    result = kfree(v7);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
