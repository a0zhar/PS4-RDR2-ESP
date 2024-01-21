ODIR	:= build
SDIR	:= source
IDIR	:= include
CFLAGS	:= -I$(IDIR) -Os -std=c11 -ffunction-sections -fdata-sections -fno-builtin -nostartfiles -nostdlib -Wall -Wextra -masm=intel -march=btver2 -mtune=btver2 -m64 -mabi=sysv -mcmodel=small -fpie -fPIC
CFILES	:= $(wildcard $(SDIR)/*.c)
SFILES	:= $(wildcard $(SDIR)/*.s)
OBJS	:= $(patsubst $(SDIR)/%.c, build/%.o, $(CFILES)) $(patsubst $(SDIR)/%.s, build/%.o, $(SFILES))

TARGET = libPS4.a

$(TARGET): $(ODIR) $(OBJS)
	@echo "Building $@..."
	@ar rcs $@ $(OBJS)
	@echo "$@ is ready!"

$(ODIR)/%.o: $(SDIR)/%.c
	@echo "Compiling $<..."
	@gcc -c -o $@ $< $(CFLAGS)

$(ODIR)/%.o: $(SDIR)/%.s
	@echo "Assembling $<..."
	@gcc -c -o $@ $< $(CFLAGS)

$(ODIR):
	@echo "Creating build directory: $(ODIR)..."
	@mkdir $@

.PHONY: clean

clean:
	@echo "Cleaning up..."
	@rm -rf $(TARGET) $(ODIR)