__int64 __fastcall gpi_config_interrupts(int *a1, int a2, char a3)
{
  int v6; // w10
  char v7; // w8
  __int64 result; // x0
  __int64 v9; // x6
  __int64 v10; // x21
  __int64 v11; // x22
  unsigned int v12; // w8
  int v13; // w9
  char v14; // w20
  int v15; // w0
  __int64 v16; // x20
  __int64 v17; // x22
  __int64 v18; // x23
  int v19; // w24
  int v20; // w25
  int v21; // w26
  int v22; // w0
  __int64 v23; // x8
  int v24; // w4
  unsigned int v25; // w19
  unsigned int v26; // w20
  int v27; // [xsp+8h] [xbp-D8h] BYREF
  __int64 v28; // [xsp+Ch] [xbp-D4h]
  _DWORD v29[2]; // [xsp+14h] [xbp-CCh]
  __int64 v30; // [xsp+1Ch] [xbp-C4h]
  int v31; // [xsp+24h] [xbp-BCh]
  int v32; // [xsp+28h] [xbp-B8h]
  __int64 v33; // [xsp+2Ch] [xbp-B4h]
  int v34; // [xsp+34h] [xbp-ACh]
  int v35; // [xsp+38h] [xbp-A8h]
  __int64 v36; // [xsp+3Ch] [xbp-A4h]
  int v37; // [xsp+44h] [xbp-9Ch]
  int v38; // [xsp+48h] [xbp-98h]
  __int64 v39; // [xsp+4Ch] [xbp-94h]
  int v40; // [xsp+54h] [xbp-8Ch]
  int v41; // [xsp+58h] [xbp-88h]
  __int64 v42; // [xsp+5Ch] [xbp-84h]
  int v43; // [xsp+64h] [xbp-7Ch]
  int v44; // [xsp+68h] [xbp-78h]
  __int64 v45; // [xsp+6Ch] [xbp-74h]
  int v46; // [xsp+74h] [xbp-6Ch]
  int v47; // [xsp+78h] [xbp-68h]
  __int64 v48; // [xsp+7Ch] [xbp-64h]
  int v49; // [xsp+84h] [xbp-5Ch]
  int v50; // [xsp+88h] [xbp-58h]
  __int64 v51; // [xsp+8Ch] [xbp-54h]
  int v52; // [xsp+94h] [xbp-4Ch]
  int v53; // [xsp+98h] [xbp-48h]
  __int64 v54; // [xsp+9Ch] [xbp-44h]
  int v55; // [xsp+A4h] [xbp-3Ch]
  int v56; // [xsp+A8h] [xbp-38h]
  __int64 v57; // [xsp+ACh] [xbp-34h]
  int v58; // [xsp+B4h] [xbp-2Ch]
  int v59; // [xsp+B8h] [xbp-28h]
  int v60; // [xsp+BCh] [xbp-24h]
  __int64 v61; // [xsp+C0h] [xbp-20h]
  __int64 v62; // [xsp+C8h] [xbp-18h]
  __int64 v63; // [xsp+D0h] [xbp-10h]
  __int64 v64; // [xsp+D8h] [xbp-8h]

  v64 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *a1;
  v28 = 127;
  v33 = 3;
  v30 = 1;
  v36 = 1;
  v27 = (v6 << 14) + 143496;
  v29[0] = 79;
  v29[1] = v27 | 0x30;
  v31 = 1;
  v32 = v27 | 0x10;
  v34 = 3;
  v35 = v27 | 0x14;
  v37 = 1;
  v38 = (v6 << 14) + 143624;
  v40 = 1;
  v41 = (v6 << 14) + 143648;
  v43 = 15;
  v44 = v27 | 0x100;
  v57 = 1;
  v46 = 0;
  v47 = v27 | 0x104;
  v49 = 0;
  v50 = (v6 << 14) + 144384;
  v52 = 0;
  v53 = (v6 << 14) + 144388;
  v58 = 1;
  v59 = (v6 << 14) + 143872;
  v7 = *((_BYTE *)a1 + 940);
  v39 = 15;
  v42 = 15;
  v45 = 0xFFFFFFFFLL;
  v48 = 0xFFFFFFFFLL;
  v51 = 0xFFFFFFFFLL;
  v54 = 0xFFFFFFFFLL;
  v55 = 0;
  v56 = (v6 << 14) + 143744;
  v60 = -1;
  v62 = 0;
  v63 = 0;
  v61 = 0;
  if ( (v7 & 1) == 0
    && (result = request_threaded_irq((unsigned int)a1[202], gpi_handle_irq, 0, 2097156, a1 + 269, a1),
        (result & 0x80000000) != 0) )
  {
    if ( a1[267] )
    {
      v26 = result;
      printk(&unk_13853, a1 + 269, 99, "gpi_config_interrupts", (unsigned int)a1[202], (unsigned int)result, v9);
      result = v26;
      v23 = *((_QWORD *)a1 + 132);
      if ( !v23 )
        goto LABEL_14;
    }
    else
    {
      v23 = *((_QWORD *)a1 + 132);
      if ( !v23 )
        goto LABEL_14;
    }
    if ( a1[266] )
    {
      v24 = a1[202];
      v25 = result;
      ipc_log_string(v23, "ch:%u %s: error request irq:%d ret:%d\n", 99, "gpi_config_interrupts", v24, result);
      result = v25;
    }
  }
  else
  {
    if ( a2 == 1 )
    {
      v10 = *((_QWORD *)a1 + 102);
      v11 = (unsigned int)((*a1 << 14) + 143496);
      v12 = a1[263] & 0xFFFFFFF7;
      if ( (a3 & 1) != 0 )
        v13 = 8;
      else
        v13 = 0;
      v14 = v12 | v13;
      a1[263] = v12 | v13;
      v15 = readl_relaxed((unsigned int *)(v10 + v11));
      writel_relaxed(v15 & 0xFFFFFF80 | v14 & 0x7F, (unsigned int *)(v10 + v11));
    }
    else
    {
      v16 = 0;
      while ( 1 )
      {
        v17 = *(unsigned int *)((char *)&v27 + v16 * 4);
        if ( !(_DWORD)v17 )
          break;
        v18 = *((_QWORD *)a1 + 102);
        v19 = *(int *)((char *)&v27 + v16 * 4 + 4);
        v20 = v29[v16 - 1];
        v21 = v29[v16];
        v22 = readl_relaxed((unsigned int *)(v18 + v17));
        writel_relaxed(v22 & ~v19 | (v21 << v20) & v19, (unsigned int *)(v18 + v17));
        v16 += 4;
        if ( v16 == 52 )
        {
          __break(0x5512u);
          break;
        }
      }
      a1[263] = 79;
    }
    result = 0;
    *((_BYTE *)a1 + 940) = 1;
  }
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
